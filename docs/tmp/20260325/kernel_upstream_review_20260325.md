# BpfReJIT v2 Kernel Patch Set Review

**审查日期**: 2026-03-25
**审查者**: Claude (模拟 BPF maintainer 标准)
**被审查分支**: `vendor/linux-framework` rejit-v2 (相对 master)
**Diff 范围**: 20 files changed, +1994 / -46 lines

---

## 1. 总体评价

**结论: 当前状态不能合入。需要至少 3-4 轮重大修改。**

这个 patch set 引入了两个大功能:
1. **BPF_PROG_REJIT**: 运行时替换 BPF 程序的 JIT 镜像
2. **kinsn (kernel instructions)**: 内联式内核指令扩展机制

两者都是有意义的功能，但实现中存在严重的架构问题、安全隐患和代码重复。核心问题是 **kinsn 建立了与 kfunc 平行的完整基础设施**，而非复用已有的 kfunc 机制。REJIT 部分虽然功能上更完整，但 swap 逻辑的脆弱性和潜在的竞态条件需要大幅重写。

**如果我是 Alexei/Daniel，我会:**
- REJIT syscall: **要求重大重构后重发** (不是 NAK 概念本身，而是 NAK 当前实现)
- kinsn 基础设施: **NAK 当前形式**，要求合并到 kfunc 框架
- orig_insns 暴露: **有条件 ACK**，需要小修

---

## 2. 逐文件 Review Comments

### 2.1 include/uapi/linux/bpf.h (+24)

**必要性: 可优化**

```
+	BPF_PROG_REJIT,
```
> 新 bpf_cmd 是合理的，REJIT 功能确实需要一个新的 syscall 命令。但名字 `BPF_PROG_REJIT` 暗示了实现细节（JIT），考虑 `BPF_PROG_RECOMPILE` 或 `BPF_PROG_REPLACE_INSNS`。

```
+#define BPF_PSEUDO_KINSN_SIDECAR 3
+#define BPF_PSEUDO_KINSN_CALL	4
```
> **NAK**。两个新 UAPI 常量过度设计。`BPF_PSEUDO_KINSN_SIDECAR` 尤其不合理 —— 它重载了 `BPF_ALU64 | BPF_MOV | BPF_K` 的 src_reg 字段来传递 metadata，这是对 BPF ISA 语义的滥用。
>
> sidecar 的本质是要传递 payload 到 JIT emit callback，这完全可以通过 kfunc 的现有 `insn->imm` + `insn->off` 字段组合来实现，或者在 kfunc_desc 中增加一个 payload 字段。不需要发明新的伪指令类型。
>
> 如果确实需要新的 pseudo call 类型，一个 `BPF_PSEUDO_KINSN_CALL` 就够了，payload 可以编码在 imm/off 中。

```
+	struct {
+		__u32		prog_fd;
+		__u32		insn_cnt;
+		__aligned_u64	insns;
+		...
+		__u32		flags;
+	} rejit;
```
> REJIT attr 结构基本合理。但缺少:
> - `license` 字段 (当前从原 prog 继承，但 REJIT 可能改变 GPL 兼容性)
> - `prog_btf_fd` / `func_info` / `line_info` (当前硬编码从原 prog 复制，不灵活)
> - 考虑是否需要 `kern_version` 字段

```
+	__u32 orig_prog_len;
+	__aligned_u64 orig_prog_insns;
```
> 在 `bpf_prog_info` 中暴露原始指令是合理的需求 (bpftool 调试)。但 `orig_prog_insns` 名字不精确 —— 这是"加载时的指令"而非"原始指令"(verifier 会 rewrite)。建议 `loaded_prog_insns` / `loaded_prog_len`。

**Maintainer 判定**: 要求修改后重发

### 2.2 include/linux/bpf.h (+88)

**必要性: 可优化 (kinsn 部分不必要，REJIT 部分必要)**

```c
+struct bpf_kinsn {
+	struct module *owner;
+	u16 max_insn_cnt;
+	u16 max_emit_bytes;
+	int (*instantiate_insn)(u64 payload, struct bpf_insn *insn_buf);
+	int (*emit_x86)(u8 *image, u32 *off, bool emit,
+			u64 payload, const struct bpf_prog *prog);
+	int (*emit_arm64)(u32 *image, int *idx, bool emit,
+			  u64 payload, const struct bpf_prog *prog);
+};
```
> **NAK 这个结构。** 这是 review 中最严重的问题。
>
> 1. `emit_x86` / `emit_arm64` 是硬编码的 per-arch callback。如果要支持 riscv / s390 / loongarch 呢？这不是可扩展的设计。kfunc 通过 BTF + trampoline + arch-agnostic calling convention 解决了这个问题。
>
> 2. `instantiate_insn` 生成 BPF 指令序列供 verifier 验证 (proof sequence)，然后 JIT 用 `emit_x86`/`emit_arm64` 生成不同的 native code。这意味着 **verifier 看到的代码和 JIT 生成的代码不同** —— 这是一个根本性的安全隐患。verifier 验证了 A 但执行的是 B。
>
> 3. 即使 proof 序列在语义上等价于 emit 结果，这种"双轨制"验证增加了巨大的信任面 (TCB)。一个 buggy 的 `emit_x86` 可以生成任意 native code，只要 `instantiate_insn` 通过了 verifier。
>
> **正确的做法**: kinsn 的 inline emit 应该通过现有 kfunc 机制来走。如果需要 inline，参考 `BPF_MOD_NOP` / `BPF_MOD_CALL` text_poke 路径，或者在 JIT 中直接内联已知的 kfunc body。

```c
+static inline bool bpf_kinsn_is_sidecar_insn(const struct bpf_insn *insn)
+{
+	return insn->code == (BPF_ALU64 | BPF_MOV | BPF_K) &&
+	       insn->src_reg == BPF_PSEUDO_KINSN_SIDECAR;
+}
```
> **NAK**。重载 ALU64/MOV/K 指令的 src_reg 来创建一种伪指令，这是对 BPF ISA 的 hack。`src_reg` 在 ALU 指令中本应为 0 (BPF_K 模式)，用 3 来标记 sidecar 绕过了 verifier 对 ALU 指令的常规检查路径。

```c
+static inline u64 bpf_kinsn_sidecar_payload(const struct bpf_insn *insn)
+{
+	return (u64)(insn->dst_reg & 0xf) |
+	       ((u64)(u16)insn->off << 4) |
+	       ((u64)(u32)insn->imm << 20);
+}
```
> 把 dst_reg, off, imm 三个字段拼成一个 52-bit payload —— 这是 ISA 编码上的 abuse。如果需要传递 payload，ldimm64 (128-bit 指令) 提供了标准方式。

```c
+struct bpf_tramp_user {
+	struct list_head list;
+	struct bpf_trampoline *tr;
+};
```
> 用于 REJIT 刷新 trampoline 的反向索引。合理的需求，但链表遍历在 rejit 热路径上不好。考虑用 XArray 或 prog->aux 中固定数量的 slot。

```c
+	struct mutex rejit_mutex;
+	struct list_head trampoline_users;
```
> `rejit_mutex` 添加到 `bpf_prog_aux` 中是合理的。但注意这增加了 **每个 BPF 程序** 的内存开销 (mutex + list_head)，即使绝大多数程序永远不会用 REJIT。考虑按需分配。

```c
+	struct bpf_insn *orig_insns;
+	u32 orig_prog_len;
```
> 同上，每个程序都保存一份原始指令副本，即使不用 REJIT。这是 O(insn_cnt) 的额外内存。应该按需分配或通过 flag 控制。

**Maintainer 判定**: kinsn 结构 NAK，其余要求修改

### 2.3 include/linux/bpf_verifier.h (+10)

**必要性: 可优化**

```c
+struct bpf_kinsn_region {
+	u32 start;
+	u16 proof_len;
+	struct bpf_insn orig[2];  /* sidecar + call */
+};
```
> 这个结构用于 lower/restore kinsn proof regions —— 在验证前展开 kinsn 为 proof 序列，验证后还原。这种 "临时展开再还原" 的模式本身就说明了 kinsn 的设计有根本问题: 如果需要展开才能验证，为什么不让用户直接写展开后的代码？

```c
+	struct bpf_kinsn_region *kinsn_regions;
+	u32 kinsn_call_cnt;
+	u32 kinsn_region_cnt;
+	u32 kinsn_region_cap;
```
> 4 个新字段加到 `bpf_verifier_env`。如果 kinsn 合并到 kfunc，这些都可以消除。

**Maintainer 判定**: 随 kinsn NAK

### 2.4 include/linux/filter.h (+11)

**必要性: 可优化**

```c
+#define BPF_CALL_KINSN(OFF, IMM)
```
> 宏定义合理，如果 kinsn 概念保留的话。但随 kinsn 重新设计。

```c
+void bpf_prog_refresh_xdp(struct bpf_prog *prog);
```
> REJIT 需要刷新 XDP dispatcher，声明合理。

**Maintainer 判定**: 部分 ACK

### 2.5 arch/x86/net/bpf_jit_comp.c (+57, -1)

**必要性: 可优化 (kinsn emit 部分不必要)**

```c
+static int emit_kinsn_desc_call(u8 **pprog, const struct bpf_prog *bpf_prog,
+				const struct bpf_insn *insn, bool emit)
+{
+	const struct bpf_kinsn *kinsn;
+	u8 scratch[BPF_MAX_INSN_SIZE];
+	...
+	ret = kinsn->emit_x86(scratch, &off, emit, payload, bpf_prog);
+	...
+	if (emit)
+		memcpy(prog, scratch, off);
+}
```
> **安全问题**: `kinsn->emit_x86` 是一个模块提供的回调函数，它可以生成 **任意 x86 机器代码**。虽然有 `max_emit_bytes` 检查，但这只限制了长度，不限制内容。一个恶意或 buggy 的内核模块可以通过 kinsn 注入任意可执行代码到 BPF JIT 镜像中。
>
> 对比 kfunc: kfunc 通过 BTF 签名 + verifier 类型检查 + 标准 calling convention 来保证安全。kinsn 完全绕过了这些保障。

```c
+static void emit_movabs_imm64(u8 **pprog, u32 dst_reg, u64 imm64)
```
> 这个辅助函数本身是合理的重构，但应该作为独立 patch 提交，不要混在 kinsn 功能中。

```c
+		if (bpf_kinsn_is_sidecar_insn(insn))
+			break;
```
> 在 x86 JIT 主循环中跳过 sidecar 指令。简洁但依赖于 sidecar 始终紧跟在 kinsn call 前面的不变量，如果 verifier rewrite 打破了这个顺序呢？

```c
+		if (src_reg == BPF_PSEUDO_KINSN_CALL) {
+			err = emit_kinsn_desc_call(&prog, bpf_prog, insn,
+						    !!rw_image);
```
> 在 `BPF_JMP | BPF_CALL` 的 dispatch 中插入 kinsn 分支。位置在 `BPF_PSEUDO_CALL` 和 `bpf_jit_get_func_addr` 之间，合理。

```c
+		pr_err("bpf_jit: unknown opcode %02x at insn %d (dst=%u src=%u off=%d imm=%d)\n",
```
> 增强错误信息是好的，但应该作为独立 patch。

**Maintainer 判定**: emit_movabs_imm64 和 error message 改进单独提交可 ACK；kinsn emit 路径 NAK

### 2.6 arch/arm64/net/bpf_jit_comp.c (+38)

**必要性: 可优化 (同 x86)**

```c
+static int emit_kinsn_desc_call_arm64(struct jit_ctx *ctx,
+				      const struct bpf_prog *bpf_prog,
+				      const struct bpf_insn *insn)
```
> 与 x86 版本相同的安全问题。`kinsn->emit_arm64` 是不受限的 native code 生成。

```c
+	if (n_insns * 4 > kinsn->max_emit_bytes)
+		return -EFAULT;
```
> Bug: ARM64 指令是 4 bytes，但 `max_emit_bytes` 的单位是 bytes，所以 `n_insns * 4` 是正确的。但 `ctx->idx - saved_idx != n_insns` 的检查假设 emit callback 正确设置了 `ctx->idx`，这个信任有问题。

**Maintainer 判定**: NAK (随 kinsn)

### 2.7 kernel/bpf/verifier.c (+739, -1) — 最大的改动文件

**必要性: 混合 (kinsn 部分不必要，辅助重构有用)**

#### 2.7.1 kfunc_desc_tab / kfunc_btf_tab 动态分配重构

```c
-	struct bpf_kfunc_desc descs[MAX_KFUNC_DESCS];
+	struct bpf_kfunc_desc *descs;
 	u32 nr_descs;
+	u32 desc_cap;
```
> **ACK**。把固定数组改为动态分配是正确的。`MAX_KFUNC_DESCS=256` 的限制在 REJIT 场景下可能不够。但应该保留一个合理的上限 (比如 4096) 以防 DoS。

```c
+static int ensure_desc_capacity(void **descs, u32 *cap, size_t elem_size, u32 need)
```
> 通用的动态数组增长函数。实现基本正确。
>
> **问题**: `kvrealloc` 在内核中不保证 old 内容被清零 (只有新增部分)，而排序后 bsearch 依赖数据的完整性。这里没有 memset 新增区域的逻辑，但因为每次 `tab->descs[tab->nr_descs++]` 后立即赋值所有字段，所以实际上是安全的。但建议添加注释说明。

#### 2.7.2 bpf_kinsn_desc_tab 并行基础设施

```c
+struct bpf_kinsn_desc {
+	const struct bpf_kinsn *kinsn;
+	s32 imm;
+	u16 offset;
+};
+
+struct bpf_kinsn_desc_tab {
+	struct bpf_kinsn_desc *descs;
+	u32 nr_descs;
+	u32 desc_cap;
+};
```
> **NAK**。这是 `bpf_kfunc_desc` / `bpf_kfunc_desc_tab` 的翻版。kinsn descriptor 的 lookup 逻辑 (`find_kinsn_desc`, `add_kinsn_call`, `kinsn_desc_cmp_by_imm_off`) 完全是 kfunc 对应函数的复制粘贴。
>
> **合并方案**: 在 `bpf_kfunc_desc` 中增加一个 `const struct bpf_kinsn *kinsn` 指针。当 `kinsn != NULL` 时，这个 kfunc 是一个 kinsn。kfunc_tab 的 lookup/sort/bsearch 逻辑完全复用。

#### 2.7.3 fetch_kinsn_desc_meta — kallsyms lookup 安全问题

```c
+static int fetch_kinsn_desc_meta(struct bpf_verifier_env *env, s32 func_id,
+				 s16 offset, const struct bpf_kinsn **kinsn)
+{
+	...
+	addr = mod ? find_kallsyms_symbol_value(mod, desc_name)
+		   : kallsyms_lookup_name(desc_name);
+	if (!addr) { ... }
+
+	*kinsn = (const struct bpf_kinsn *)addr;
+	if ((*kinsn)->owner != mod) { ... }
```
> **严重安全问题**:
>
> 1. `kallsyms_lookup_name` 返回的地址被直接当作 `struct bpf_kinsn *` 解引用。如果 `func_name + "_desc"` 碰巧匹配到一个不是 `bpf_kinsn` 结构的符号 (比如一个普通函数或变量)，就会造成类型混淆。
>
> 2. `owner` 字段检查不够: 一个恶意模块可以 export 一个名为 `XXX_desc` 的 `bpf_kinsn` 结构，其 `owner` 设为 NULL (假装是 vmlinux 的)。
>
> 3. 这里没有任何 BTF 类型验证。kfunc 通过 BTF_KIND_FUNC + func_proto 来验证函数签名，kinsn 完全没有类似机制。
>
> **正确做法**: 使用 kfunc 的 BTF 注册机制 (BTF_KFUNCS + `register_btf_kfunc_id_set`)，在注册时关联 kinsn descriptor，而不是运行时通过 kallsyms 动态查找。

#### 2.7.4 lower_kinsn_proof_regions / restore_kinsn_proof_regions

```c
+static int lower_kinsn_proof_regions(struct bpf_verifier_env *env)
+{
+	...
+	for (i = env->prog->len - 1; i >= 0; i--) {
+		...
+		cnt = kinsn->instantiate_insn(bpf_kinsn_sidecar_payload(sidecar),
+					      proof_buf);
+		...
+		err = verifier_remove_insns(env, i - 1, 1);
+		new_prog = bpf_patch_insn_data(env, i - 1, proof_buf, cnt);
+	}
+}
```
> **架构问题**: 这个 "展开 → 验证 → 还原" 的三步模式极其脆弱:
>
> 1. 倒序遍历修改指令数组，同时调整所有之前记录的 region start。O(n^2) 复杂度且容易出 off-by-one。
> 2. `verifier_remove_insns` + `bpf_patch_insn_data` 会重新分配 prog 和 insn_aux_data，每次 kinsn 调用都做一次。O(n*k) 其中 k 是 kinsn 调用数。
> 3. 还原时 `scrub_restored_kinsn_aux` 清理 aux 数据，但如果 verifier 过程中修改了 aux 数据的其他字段（比如 jt），就可能丢失信息。
>
> **根本问题**: 如果 kinsn 只是一种特殊的 kfunc，就不需要这个机制。verifier 直接验证 kfunc call 语义即可。

#### 2.7.5 bpf_check() 中的排序变更

```c
+	ret = check_btf_info_early(env, attr, uattr);
+	...
+	ret = add_subprog_and_kfunc(env);
+	...
+	ret = lower_kinsn_proof_regions(env);
+	...
 	env->explored_states = kvzalloc_objs(...)
```
> 把 `check_btf_info_early` 和 `add_subprog_and_kfunc` 移到 `explored_states` 分配之前。这改变了 verifier 的初始化顺序，可能影响错误路径的 cleanup。需要确认 `skip_full_check` label 处的清理逻辑覆盖了新增的 early 分配。
>
> 特别是: 如果 `lower_kinsn_proof_regions` 失败，`env->explored_states` 还没分配，但 `skip_full_check` 路径会 `kvfree(env->explored_states)` —— 这里 kvfree(NULL) 是安全的，所以没有 bug，但代码流很容易让人困惑。

#### 2.7.6 do_misc_fixups 中的 kinsn fallback

```c
+		if (bpf_kinsn_is_sidecar_insn(insn)) {
+			...
+			if (prog->jit_requested && bpf_kinsn_has_native_emit(kinsn))
+				goto next_insn;
+
+			ret = verifier_remove_insns(env, i + delta + 1, 1);
+			new_prog = bpf_patch_insn_data(env, i + delta, insn_buf, cnt);
```
> 如果 JIT 可用且有 native emit，保留 sidecar+call 让 JIT 处理。否则展开为 proof 序列。
>
> **问题**: `i + delta` 的索引计算容易出错。`delta` 在循环中累积，但 `insn` 指针也在更新，两者必须保持同步。此处 `i++; goto next_insn` 使得 `i` 前进了但只跳过了一条指令，而实际替换可能是 N 条。需要仔细验证 `delta` 的更新逻辑。

#### 2.7.7 disasm_kfunc_name → disasm_call_name 重命名

> 合理的重构，让函数同时处理 kfunc 和 kinsn 的名称解析。但 `btf_type_by_id` 返回 NULL 时的 fallback `"<invalid>"` 应该触发 WARN 而非静默返回。

**Maintainer 判定**: 动态 desc_tab 重构 ACK；kinsn 并行基础设施 NAK；verifier 初始化顺序变更需要更多讨论

### 2.8 kernel/bpf/syscall.c (+697, -1) — REJIT 核心实现

**必要性: 必要 (功能核心)，但实现需要大幅修改**

#### 2.8.1 bpf_free_kfunc_desc_tab / bpf_free_kinsn_desc_tab

```c
-	kfree(prog->aux->kfunc_tab);
+	bpf_free_kfunc_desc_tab(prog->aux->kfunc_tab);
```
> 正确的修改，配合 desc_tab 的动态分配。

#### 2.8.2 orig_insns 保存

```c
+	prog->aux->orig_insns = kvmemdup(prog->insns, bpf_prog_insn_size(prog),
+					 GFP_USER);
```
> **性能问题**: 每个 BPF 程序加载时都分配 orig_insns 副本，即使永远不用 REJIT。对于有 10000+ BPF 程序的系统 (如 Cilium)，这是不可忽视的内存开销。
>
> **建议**: 只在第一次 REJIT 调用时保存 orig_insns，或者提供 `BPF_F_KEEP_ORIG_INSNS` flag。

#### 2.8.3 bpf_prog_rejit_supported

```c
+static bool bpf_prog_rejit_supported(const struct bpf_prog *prog)
+{
+	if (!prog->jited || prog->is_func)
+		return false;
+	if (bpf_prog_is_offloaded(aux) || bpf_prog_is_dev_bound(aux))
+		return false;
+	if (prog->type == BPF_PROG_TYPE_EXT && !aux->dst_prog)
+		return false;
```
> 检查合理。但缺少:
> - `prog->aux->priv_stack_ptr` 检查: 如果新 prog 的 stack 需求不同呢？
> - LSM hook 检查: LSM 可能限制某些 prog 类型的 REJIT

#### 2.8.4 bpf_prog_rejit_update_poke_tab — tail_call 更新

```c
+static int bpf_prog_rejit_update_poke_tab(struct bpf_prog *prog,
+					   struct bpf_prog *tmp)
+{
+	...
+	for (i = 0; i < prog->aux->size_poke_tab; i++) {
+		...
+		WRITE_ONCE(old_poke->tailcall_target_stable, false);
+		old_poke->tailcall_target = new_poke->tailcall_target;
+		old_poke->tailcall_bypass = new_poke->tailcall_bypass;
+		old_poke->bypass_addr     = new_poke->bypass_addr;
+		old_poke->adj_off         = new_poke->adj_off;
+		WRITE_ONCE(old_poke->tailcall_target_stable, true);
+		...
+	}
```
> **TOCTOU 风险**: 在 `stable = false` 和 `stable = true` 之间，如果有并发的 `map_poke_run` 检查 stable 标志，它会跳过这个 entry。但 poke 地址已经指向了新的 JIT 镜像（其中的 `tailcall_target` 等已更新），而旧镜像可能还有 CPU 在执行。
>
> 更关键的是: `tailcall_target` 等字段的更新不是原子的。如果 `poke_run` 在 `old_poke->tailcall_target = new_poke->tailcall_target` 和 `old_poke->tailcall_bypass = new_poke->tailcall_bypass` 之间读取了这些字段，会看到不一致的状态。
>
> **建议**: 这些字段的更新应该用 `smp_store_release` / `smp_load_acquire` 配对，或者 poke_mutex 应该覆盖整个更新序列（目前已经这样做了，但要确认所有 poke_run 读者都在 mutex 保护下）。

#### 2.8.5 bpf_prog_rejit_poke_target_phase — 全量扫描所有 map

```c
+static void bpf_prog_rejit_poke_target_phase(struct bpf_prog *prog,
+					      bool is_insert)
+{
+	struct bpf_map *map;
+	u32 id = 0;
+
+	while ((map = bpf_map_get_curr_or_next(&id))) {
+		...
+		if (map->map_type != BPF_MAP_TYPE_PROG_ARRAY) { ... }
+		...
+		for (key = 0; key < array->map.max_entries; key++) {
+			if (array->ptrs[key] != prog)
+				continue;
+			...
+		}
+	}
+}
```
> **性能问题**: O(所有 map * 所有 entry) 的线性扫描。在大规模部署中可能有数千个 prog_array map，每个有数百个 entry。REJIT 期间的延迟会很高。
>
> **竞态条件**: `array->ptrs[key] != prog` 是 lockless 的 pre-check。注释说"benign"，但考虑: delete phase 把 jmp → nop，insert phase 把 nop → jmp。如果在 delete phase 遗漏了一个 slot (因为并发更新把 prog 加入了该 slot)，那个 slot 的 direct jump 会指向旧的 bpf_func 地址（swap 后）—— 这是 **use-after-free**，因为旧镜像会被释放。
>
> 虽然注释声称"miss a newly added slot until that update path repokes it"，但这依赖于 map_update 路径在 REJIT 完成后会自动 repoke，而 map_update 路径看到的 bpf_func 已经是新的了，所以确实会 poke 到正确地址。但窗口期内的 use-after-free 仍然存在。

#### 2.8.6 bpf_prog_rejit_swap — 核心 swap 逻辑

```c
+static void bpf_prog_rejit_swap(struct bpf_prog *prog, struct bpf_prog *tmp)
+{
+	swap(prog->aux->orig_insns, tmp->aux->orig_insns);
+	swap(prog->aux->orig_prog_len, tmp->aux->orig_prog_len);
+	swap(prog->aux->used_btfs, tmp->aux->used_btfs);
+	...（25+ swap 调用）
+	swap(prog->aux->kinsn_tab, tmp->aux->kinsn_tab);
+
+	bpf_prog_kallsyms_del_all(prog);
+
+	swap(prog->aux->func, tmp->aux->func);
+	...
+	memcpy(prog->insnsi, tmp->insnsi, bpf_prog_insn_size(tmp));
+	prog->len = tmp->len;
+
+	smp_wmb();
+	WRITE_ONCE(prog->bpf_func, tmp->bpf_func);
```
> **严重问题**:
>
> 1. **25+ 个 swap 调用**: 这是极度脆弱的代码。每次内核添加一个新的 `bpf_prog_aux` 字段，都必须检查是否需要在这里 swap。遗漏一个字段就是 bug。
>
> 2. **`memcpy(prog->insnsi, tmp->insnsi, ...)`**: 这假设 `prog` 的 flexible array 有足够空间容纳 `tmp` 的指令。虽然前面有 `bpf_prog_size(tmp->len) > prog->pages * PAGE_SIZE` 检查，但 flexible array 的实际分配大小可能不等于 `pages * PAGE_SIZE`。
>
> 3. **`smp_wmb()` + `WRITE_ONCE(prog->bpf_func, ...)`**: 这个内存屏障只保证 metadata 写入在 bpf_func 发布之前可见。但读端（运行 BPF 程序的 CPU）没有对应的 `smp_rmb()`。在 ARM 等弱序架构上，这不够。需要 `smp_store_release` + `smp_load_acquire` 配对，或者 `rcu_assign_pointer`。
>
> 4. **`bpf_prog_kallsyms_del_all(prog)` + `bpf_prog_kallsyms_add(prog)`**: 在 swap 过程中短暂地从 kallsyms 删除再添加。这个窗口期内，perf 采样到 prog 地址会无法解析符号。应该确保这个操作在 `synchronize_rcu` 之后才删除旧的。

```c
+	prog->gpl_compatible = tmp->gpl_compatible;
+	prog->cb_access = tmp->cb_access;
+	...（10+ 个 bool 字段复制）
```
> 同 swap 问题: 每个新增 bool 字段都需要在这里添加。应该考虑把这些字段分组到一个 sub-struct 中，然后 swap 整个 sub-struct。

#### 2.8.7 bpf_prog_rejit — 主函数

```c
+static int bpf_prog_rejit(union bpf_attr *attr)
+{
+	...
+	if (!capable(CAP_BPF) || !capable(CAP_SYS_ADMIN))
+		return -EPERM;
```
> 要求 CAP_BPF + CAP_SYS_ADMIN 是正确的。但应该也检查 BPF token 授权（与 BPF_PROG_LOAD 对齐）。

```c
+	load_attr.prog_flags = (prog->sleepable ? BPF_F_SLEEPABLE : 0) |
+			       (prog->aux->xdp_has_frags ? BPF_F_XDP_HAS_FRAGS : 0);
```
> 只复制了两个 flag。如果原 prog 有其他 flag (BPF_F_ANY_ALIGNMENT, BPF_F_TEST_RND_HI32 等) 呢？应该从原 prog 复制所有 prog_flags。

```c
+	err = bpf_check(&tmp, &load_attr, load_uattr,
+			BPF_PROG_REJIT_LOAD_ATTR_SIZE);
```
> 使用 `BPF_PROG_REJIT_LOAD_ATTR_SIZE = offsetofend(union bpf_attr, keyring_id)` 作为 attr size —— 这假设 rejit attr 和 prog_load attr 的 overlap 是安全的。但 `union bpf_attr` 的 `prog_load` 和 `rejit` 成员是不同的 struct，字段布局不同。这里把 rejit 的字段映射到 prog_load 的字段是一个 hack，随着 UAPI 演进容易崩。
>
> **建议**: 抽取 verifier 需要的参数为独立结构，而不是假装 rejit attr 是 prog_load attr。

#### 2.8.8 rollback 逻辑

```c
+static int bpf_prog_rejit_rollback(struct bpf_prog *prog, struct bpf_prog *tmp,
+				    bpf_func_t new_bpf_func,
+				    struct bpf_jit_poke_descriptor *saved_poke_tab,
+				    u32 saved_poke_cnt)
+{
+	bpf_prog_rejit_poke_target_phase(prog, false);
+	bpf_prog_rejit_swap(prog, tmp);
+	...
+	bpf_prog_rejit_poke_target_phase(prog, true);
+	...
+}
```
> rollback 执行第二次 swap + poke target 更新。但如果 rollback 本身也失败了 (比如 text_poke 失败)，系统进入不一致状态: `retain_old_image = true`，旧 JIT 镜像不释放。这是一个内存泄漏（直到 prog 被 unload），但至少不会 crash。
>
> 不过更严重的是: rollback 失败后，prog 的 bpf_func 可能指向一个"半更新"的状态。需要考虑是否应该在这种情况下让 prog 进入"不可执行"状态。

#### 2.8.9 bpf_prog_get_info_by_fd 中暴露 orig_insns

```c
+	ulen = info.orig_prog_len;
+	info.orig_prog_len = prog->aux->orig_prog_len;
+	if (info.orig_prog_len && ulen) {
+		if (bpf_dump_raw_ok(file->f_cred)) {
+			uinsns = u64_to_user_ptr(info.orig_prog_insns);
+			ulen = min_t(u32, info.orig_prog_len, ulen);
+			if (copy_to_user(uinsns, prog->aux->orig_insns, ulen))
+				return -EFAULT;
+		} else {
+			info.orig_prog_insns = 0;
+		}
+	}
```
> 权限检查正确 (`bpf_dump_raw_ok`)。但 `min_t(u32, ...)` 的溢出检查缺失: 如果 `ulen` 是 0xFFFFFFFF 会怎样？需要确保 `copy_to_user` 的 size 参数不会溢出 `size_t`。

**Maintainer 判定**: REJIT 概念有价值，但实现需要 2-3 轮重大修改

### 2.9 kernel/bpf/trampoline.c (+53)

**必要性: 必要**

```c
+	tu = kzalloc(sizeof(*tu), GFP_KERNEL);
+	if (!tu)
+		return -ENOMEM;
+
+	tu->tr = tr;
+	mutex_lock(&link->link.prog->aux->rejit_mutex);
+	mutex_lock(&tr->mutex);
```
> **锁序问题**: `rejit_mutex` → `tr->mutex`。需要确认整个代码库中这两个锁的获取顺序一致，否则会死锁。
>
> 在 `bpf_trampoline_refresh_prog` 中: `rejit_mutex` (caller holds) → `tr->mutex`。顺序一致。
>
> 在 `bpf_trampoline_unlink_prog` 中: `rejit_mutex` → `tr->mutex`。一致。
>
> OK，锁序一致。但应该在代码注释中 document 这个锁序不变量。

```c
+int bpf_trampoline_refresh_prog(struct bpf_prog *prog, bpf_func_t old_bpf_func)
+{
+	...
+	list_for_each_entry(tu, &prog->aux->trampoline_users, list) {
+		...
+		err = bpf_trampoline_update(tr, true);
+		...
+	}
```
> `bpf_trampoline_update` 会重建整个 trampoline 镜像。这比精确 text_poke 更安全但更慢。合理的 tradeoff，因为 REJIT 不是 hot path。
>
> 但 `old_bpf_func` 参数没有被使用！函数签名中有 `old_bpf_func` 但函数体中完全没用到。这是 dead parameter，应该删除或使用。

**Maintainer 判定**: 要求修改后 ACK

### 2.10 kernel/bpf/bpf_struct_ops.c (+108)

**必要性: 必要**

```c
+static void *find_call_site(void *image, u32 image_size, void *old_target)
+{
+#ifdef CONFIG_X86
+	for (; start + CALL_INSN_SIZE <= end;) {
+		struct insn insn;
+		...
+		if (*p == CALL_INSN_OPCODE) {
+			s32 disp = *(s32 *)(p + 1);
+			void *target = (void *)((unsigned long)(p + CALL_INSN_SIZE) + disp);
+			if (target == old_target)
+				return p;
+		}
```
> **安全问题**: 线性扫描 trampoline 镜像来查找 CALL 指令。如果镜像中有巧合的 `0xE8` 字节（作为其他指令的 immediate operand），会误匹配。
>
> 使用了 `insn_init` / `insn_get_length` 进行正确的 x86 反汇编，所以实际上不会误匹配——函数会按指令边界遍历。这是正确的。
>
> 但 ARM64 版本 `aarch64_insn_is_bl` + `aarch64_get_branch_offset` 的正确性取决于对齐: ARM64 指令是 4-byte 对齐的，`start += sizeof(u32)` 保证了这一点。OK。

```c
+int bpf_struct_ops_refresh_prog(struct bpf_prog *prog, bpf_func_t old_bpf_func)
+{
+	...
+	for (i = 0; i < st_map->funcs_cnt; i++) {
+		...
+		if (st_map->links[i]->prog != prog)
+			continue;
+		...
+		err = bpf_arch_text_poke(call_site, BPF_MOD_CALL,
+					 BPF_MOD_CALL,
+					 (void *)old_bpf_func,
+					 (void *)prog->bpf_func);
```
> `bpf_arch_text_poke` 的第二/三个参数都是 `BPF_MOD_CALL`。这表示"旧的是 CALL，新的也是 CALL"。正确。
>
> 但 `links[i]` 为 NULL 时 break 而非 continue —— 如果中间有一个 NULL link 但后面还有非 NULL link 呢？应该用 continue。不过 struct_ops 的 link 数组似乎是密集的，所以 break 可能是正确的。需要验证。

**Maintainer 判定**: 要求小修后 ACK

### 2.11 kernel/bpf/core.c (+11, -1)

**必要性: 必要**

```c
+	mutex_init(&fp->aux->rejit_mutex);
+	INIT_LIST_HEAD(&fp->aux->trampoline_users);
```
> 每个 prog 都初始化 rejit_mutex —— 前面提到的内存开销问题。

```c
-	kfree(prog->aux->kfunc_tab);
+	bpf_free_kfunc_desc_tab(prog->aux->kfunc_tab);
```
> 配合动态分配。正确。

```c
+	INIT_LIST_HEAD_RCU(&ksym->lnode);
```
> 在 `__bpf_ksym_del` 中，删除后重新初始化 lnode。这是为了让 REJIT 后的 `bpf_prog_kallsyms_add` 不会 double-add。合理但 hacky —— 更好的做法是在 del 时设一个 flag。

```c
+	/* Poison freed JIT text ... */
 	WARN_ONCE(bpf_arch_text_invalidate(ptr, size),
```
> 添加注释解释为什么 invalidate。纯注释添加，ACK。

**Maintainer 判定**: ACK with nit

### 2.12 kernel/bpf/dispatcher.c (+23, -1)

**必要性: 必要**

```c
-static void bpf_dispatcher_update(struct bpf_dispatcher *d, int prev_num_progs)
+static void bpf_dispatcher_update(struct bpf_dispatcher *d, int prev_num_progs,
+				  bool expedited)
 {
	...
-	synchronize_rcu();
+	if (expedited)
+		synchronize_rcu_expedited();
+	else
+		synchronize_rcu();
```
> `synchronize_rcu_expedited` 用于 REJIT 路径减少延迟。合理但需要注意: `expedited` 会发送 IPI 到所有 CPU，在大型系统上有性能影响。应该只在 REJIT 路径使用。

```c
+void bpf_dispatcher_refresh_prog(struct bpf_dispatcher *d,
+				 struct bpf_prog *prog)
+{
+	mutex_lock(&d->mutex);
+	if (!d->image || !bpf_dispatcher_find_prog(d, prog))
+		goto out;
+	bpf_dispatcher_update(d, d->num_progs, true);
```
> 逻辑简洁。`bpf_dispatcher_find_prog` 返回 prog 在 dispatcher 中的位置，如果不在则跳过。

**Maintainer 判定**: ACK

### 2.13 kernel/bpf/btf.c (+7, -1)

**必要性: 必要**

```c
-	if (prog_type == BPF_PROG_TYPE_EXT)
+	if (prog_type == BPF_PROG_TYPE_EXT) {
+		if (!prog->aux->dst_prog) {
+			bpf_log(log, "extension program missing dst_prog\n");
+			return -EINVAL;
+		}
 		prog_type = prog->aux->dst_prog->type;
+	}
```
> 修复了 EXT 程序在 dst_prog 为 NULL 时的 NULL deref。这是一个独立的 bug fix，应该单独提交并 CC stable。

**Maintainer 判定**: ACK (独立 bug fix)

### 2.14 kernel/bpf/disasm.c (+2)

**必要性: 可优化**

```c
+	else if (insn->src_reg == BPF_PSEUDO_KINSN_CALL)
+		snprintf(buff, len, "kinsn-function");
```
> 随 kinsn 走。

### 2.15 net/bpf/test_run.c (-5)

**必要性: 需要讨论**

```c
-	if (repeat > 1)
-		bpf_prog_change_xdp(NULL, prog);
...
-	if (repeat > 1)
-		bpf_prog_change_xdp(prog, NULL);
```
> 删除了 XDP test_run 中 repeat > 1 时的 dispatcher 注册/注销。注释/commit message 中没有解释为什么。
>
> 这看起来是一个 **功能回归**: XDP test_run 在 repeat > 1 时使用 dispatcher 来优化性能（避免 indirect call），删除后性能会下降。需要确认这不是一个意外的改动。

**Maintainer 判定**: 需要解释

### 2.16 net/core/filter.c (+5)

**必要性: 必要**

```c
+void bpf_prog_refresh_xdp(struct bpf_prog *prog)
+{
+	bpf_dispatcher_refresh_prog(BPF_DISPATCHER_PTR(xdp), prog);
+}
```
> 简洁的 wrapper。ACK。

### 2.17 tools/include/uapi/linux/bpf.h (+24)

> UAPI 的 tools/ 副本。与 include/uapi/ 同步。

### 2.18 tools/testing/selftests/bpf/get_original_poc.c (+103)

**必要性: 可优化**

> 测试程序验证 orig_insns 暴露功能。代码质量一般:
> - 缺少 `SPDX-License-Identifier` 头 (实际有，OK)
> - 硬编码了 `XDP_PASS` 值
> - 没有使用 libbpf，直接 syscall
>
> 作为 POC 可以，但上游 selftest 应该用 test_progs 框架。

### 2.19 tools/testing/selftests/bpf/jit_disasm_helpers.c (+30)

**必要性: 可优化**

```c
+static void normalize_movabs_imm_hex(char *buf, size_t buf_sz)
+{
+	...
+	mag = strtoull(digits, &end, 16);
+	...
+	snprintf(tmp, sizeof(tmp), "%.*s$0x%llx%s",
+		 (int)prefix_len, buf, 0ULL - mag, end);
```
> 规范化负数 movabs 的十六进制表示。这看起来是为了让 JIT 输出的 disassembly 在不同 LLVM 版本间一致。与 REJIT 无关，应该独立提交。
>
> **Bug**: `0ULL - mag` 当 mag = 0 时结果是 0，当 mag = 1 时结果是 0xFFFFFFFFFFFFFFFF。这个计算在数学上是 2^64 - mag，用于把 `-0x1` 转换为 `0xFFFFFFFFFFFFFFFF`。行为正确。

---

## 3. 架构 NAK 清单

### NAK-1: kinsn 并行基础设施

**问题**: `struct bpf_kinsn`, `bpf_kinsn_desc`, `bpf_kinsn_desc_tab`, `add_kinsn_call`, `fetch_kinsn_desc_meta`, `find_kinsn_desc`, `kinsn_desc_cmp_by_imm_off`, `bpf_free_kinsn_desc_tab`, `bpf_jit_find_kinsn_desc`, `bpf_jit_get_kinsn_payload`, `bpf_prog_has_kinsn_call`, `lower_kinsn_proof_regions`, `restore_kinsn_proof_regions`, `validate_kinsn_proof_seq`, `scrub_restored_kinsn_aux`, `alloc_kinsn_proof_regions`, `adjust_prior_kinsn_region_starts`, `build_kinsn_inst_seq`, `check_kinsn_sidecar_insn`, `bpf_kinsn_is_subprog_start`, `bpf_verifier_find_kinsn_sidecar`, `bpf_prog_find_kinsn_sidecar`, `bpf_kinsn_has_native_emit` —— 这是 **~500 行** 的代码，完全平行于 kfunc 基础设施。

**NAK 原因**:
1. 与 kfunc 基础设施功能重叠 >80%
2. 绕过 verifier 的类型安全保证 (emit callback 生成任意 native code)
3. 通过 kallsyms 动态查找 descriptor，没有 BTF 类型验证
4. sidecar 伪指令是对 BPF ISA 的 abuse

### NAK-2: "双轨制"验证 (proof sequence != native emit)

**问题**: `instantiate_insn` 生成 BPF 指令让 verifier 验证，`emit_x86`/`emit_arm64` 生成实际执行的 native code。verifier 看到的不是实际执行的代码。

**NAK 原因**: 这在原则上违反了 BPF verifier 的核心安全保证。整个 BPF 安全模型建立在"verifier 验证了什么 = JIT 生成了什么"的假设上。打破这个假设需要极强的 justification，以及 formal equivalence proof。

### NAK-3: sidecar 伪指令 (BPF_PSEUDO_KINSN_SIDECAR)

**问题**: 重载 ALU64/MOV/K 的 src_reg 创建一种"隐形"伪指令。

**NAK 原因**: 违反 BPF ISA 的编码规范。src_reg 在 K-mode 指令中应该为 0。这会混淆所有解析 BPF 指令的工具 (bpftool, libbpf, 第三方分析器)。

---

## 4. kfunc 复用差距分析

### 当前状态

| 组件 | kfunc | kinsn | 是否重复 |
|------|-------|-------|----------|
| 注册机制 | `register_btf_kfunc_id_set` + BTF | kallsyms lookup `_desc` 后缀 | 功能重复，kinsn 更弱 |
| Descriptor table | `bpf_kfunc_desc_tab` | `bpf_kinsn_desc_tab` | 完全重复 |
| Lookup | `find_kfunc_desc` (bsearch) | `find_kinsn_desc` (bsearch) | 完全重复 |
| 添加 | `add_kfunc_call` | `add_kinsn_call` | 90% 重复 |
| Meta 获取 | `fetch_kfunc_meta` | `fetch_kinsn_desc_meta` | 50% 重复 |
| 排序 | `kfunc_desc_cmp_by_imm_off` | `kinsn_desc_cmp_by_imm_off` | 完全重复 |
| 释放 | `bpf_free_kfunc_desc_tab` | `bpf_free_kinsn_desc_tab` | 完全重复 |
| Verifier dispatch | `check_kfunc_call` | proof lower/restore | 功能不同 |
| JIT dispatch | kfunc trampoline call | kinsn emit callback | 功能不同 |
| UAPI 常量 | `BPF_PSEUDO_KFUNC_CALL` | `BPF_PSEUDO_KINSN_CALL` + `SIDECAR` | 2 个新常量 |

### 理想状态

| 组件 | 统一方案 |
|------|----------|
| 注册 | 扩展 `register_btf_kfunc_id_set`，增加 `BPF_KFUNC_FL_INLINE` flag |
| Descriptor | 在 `bpf_kfunc_desc` 中增加 `const struct bpf_kinsn *inline_ops` 字段 |
| Lookup/Add/Sort | 完全复用 kfunc 的 |
| Verifier | 对 inline kfunc，在 `check_kfunc_call` 中检查 inline_ops->instantiate_insn 的结果 |
| JIT | 在 kfunc call 的 JIT 路径中，如果 inline_ops 存在且有 native emit，使用它 |
| UAPI | `BPF_PSEUDO_KFUNC_CALL` 即可，通过 kfunc_desc 的 flag 区分 |

### 差距分析

1. **kfunc registration 不支持 inline ops**: 需要扩展 `struct btf_kfunc_id_set` 或创建新的注册 API
2. **kfunc verifier 只做类型检查**: 需要增加对 inline proof sequence 的验证能力
3. **payload 传递**: kfunc 通过参数传递数据（R1-R5），kinsn 通过 sidecar 的 52-bit payload。需要统一为 kfunc 参数传递
4. **native emit**: kfunc 通过 trampoline indirect call，kinsn 通过 direct inline。需要在 JIT 中为特定 kfunc 添加 inline 优化路径

### 所需工作量

统一到 kfunc 需要:
- 扩展 `bpf_kfunc_desc` (~20 行)
- 移除整个 kinsn_desc_tab 基础设施 (~200 行删除)
- 修改 kfunc registration API (~50 行)
- 在 kfunc JIT 路径中添加 inline 分支 (~30 行)
- 修改 verifier 的 kfunc call 检查添加 proof 验证 (~100 行)

总计: **~200 行新增，~500 行删除**，净减少 ~300 行。

---

## 5. Patch 拆分方案

建议拆分为以下 patch series:

### Series 1: 基础设施改进 (5 patches, 可独立合入)

1. **bpf: fix NULL deref in btf_prepare_func_args for EXT programs**
   - btf.c: 添加 dst_prog NULL 检查
   - Fixes tag, CC stable

2. **bpf: improve x86 JIT error messages for unknown opcodes**
   - bpf_jit_comp.c: 增强 pr_err 输出

3. **bpf: refactor emit_mov_imm64 to emit_movabs_imm64 for x86**
   - bpf_jit_comp.c: 新增 emit_movabs_imm64，重构 emit_priv_frame_ptr

4. **bpf: convert kfunc_desc_tab from fixed array to dynamic allocation**
   - verifier.c: kfunc_desc_tab, kfunc_btf_tab 使用 kvrealloc
   - core.c, syscall.c: 适配 free 函数

5. **bpf: initialize ksym lnode after erase from kallsyms tree**
   - core.c: INIT_LIST_HEAD_RCU

### Series 2: orig_insns 暴露 (2 patches)

6. **bpf: save original program instructions at load time**
   - syscall.c: 在 bpf_prog_load 中保存 orig_insns
   - 可选: 添加 BPF_F_KEEP_ORIG_INSNS flag

7. **bpf: expose original program instructions via bpf_prog_info**
   - syscall.c: bpf_prog_get_info_by_fd 中添加 orig_prog_insns
   - UAPI: bpf_prog_info 增加字段
   - selftest: get_original_poc

### Series 3: BPF_PROG_REJIT 核心 (6-8 patches)

8. **bpf: add rejit_mutex and trampoline reverse index to prog_aux**
   - bpf.h, core.c: 添加 mutex 和 list

9. **bpf: add BPF_PROG_REJIT syscall command skeleton**
   - UAPI: bpf_cmd, bpf_attr.rejit
   - syscall.c: 基本的 rejit 函数框架 (验证 + 创建 tmp prog)

10. **bpf: implement REJIT program swap logic**
    - syscall.c: bpf_prog_rejit_swap

11. **bpf: add trampoline refresh for REJIT**
    - trampoline.c: bpf_trampoline_refresh_prog, link/unlink 中维护 reverse index

12. **bpf: add struct_ops refresh for REJIT**
    - bpf_struct_ops.c: find_call_site, bpf_struct_ops_refresh_prog

13. **bpf: add XDP dispatcher refresh for REJIT**
    - dispatcher.c: bpf_dispatcher_refresh_prog, expedited rcu
    - filter.c: bpf_prog_refresh_xdp

14. **bpf: add tail_call poke_tab update for REJIT**
    - syscall.c: bpf_prog_rejit_update_poke_tab, poke_target_phase

15. **bpf: add REJIT rollback and error handling**
    - syscall.c: bpf_prog_rejit_rollback, post_swap_sync

### Series 4: kinsn 机制 (应该在合并到 kfunc 后再提交)

16. **bpf: extend kfunc infrastructure for inline emit**
    - 在 kfunc 框架中支持 inline native code generation
    - 合并 kinsn 功能到 kfunc

---

## 6. Action Items (按优先级排序)

### P0 (必须修复才能继续 review)

1. **合并 kinsn 到 kfunc 基础设施** — 消除平行基础设施，使用 kfunc 的 BTF 注册机制
2. **消除 "双轨制" 验证** — verifier 验证的代码必须 == JIT 生成的代码，或提供 formal proof
3. **删除 BPF_PSEUDO_KINSN_SIDECAR** — 不要创建新的伪指令类型来传递 payload
4. **修复 bpf_prog_rejit_swap 的内存序问题** — 使用 `smp_store_release` / acquire，或 RCU publish

### P1 (安全相关)

5. **添加 REJIT 的 BPF token 授权检查**
6. **修复 poke_target_phase 的竞态条件** — delete/insert 窗口期的 use-after-free 风险
7. **不要通过 kallsyms 查找 kinsn descriptor** — 使用显式注册
8. **限制 emit callback 生成的 native code** — 至少需要 code range 检查

### P2 (性能/质量)

9. **orig_insns 改为按需分配** — 不要给所有 prog 增加内存开销
10. **rejit_mutex 改为按需分配** — 或者用 prog-level 的现有锁
11. **poke_target_phase 的全量 map 扫描改为反向索引**
12. **bpf_prog_rejit_swap 的 25+ swap 改为 sub-struct swap**
13. **从 rejit attr 正确复制所有 prog_flags**

### P3 (代码质量)

14. **解释为什么删除 test_run 中的 XDP dispatcher 注册**
15. **独立提交 jit_disasm_helpers 的 normalize 改动**
16. **添加 lockdep 注释说明 rejit_mutex → tr->mutex 锁序**
17. **bpf_trampoline_refresh_prog 中删除未使用的 old_bpf_func 参数**
18. **selftest 改用 test_progs 框架**

---

## 7. 与已有内核机制的重复检查

### 7.1 livepatch

REJIT 的 code swap 类似 livepatch 的 `klp_patch`，但 BPF 程序不是内核函数，livepatch 的 consistency model (per-task) 不直接适用。REJIT 使用 RCU 来确保旧代码不再执行后才释放，这是合理的。**不重复**。

### 7.2 ftrace text_poke

REJIT 使用了 `bpf_arch_text_poke` (struct_ops refresh)，这是对 ftrace text_poke 的正确复用。**不重复，正确复用**。

### 7.3 kprobes instruction replacement

kprobes 替换单条指令，REJIT 替换整个 JIT 镜像。不同粒度，不重复。

### 7.4 module BTF 处理

kinsn 的 `fetch_kinsn_desc_meta` 通过 kallsyms 查找，绕过了模块 BTF 的标准注册路径。这是对已有机制的 **不当绕过**，应该使用 `register_btf_kfunc_id_set`。

### 7.5 bpf_prog_pack allocator

REJIT 没有重新发明 prog_pack，新 JIT 镜像通过标准 `bpf_prog_select_runtime` 分配。**正确复用**。

---

## 8. 安全审查总结

### 8.1 非特权用户滥用

REJIT 要求 `CAP_BPF + CAP_SYS_ADMIN`，对非特权用户安全。但缺少 BPF token 检查。

### 8.2 TOCTOU 竞争

- **poke_target_phase**: delete/insert 窗口期存在竞态，已在 2.8.5 中详述。
- **bpf_prog_rejit_swap**: `smp_wmb()` 不足以在弱序架构上保证安全。
- **rejit_mutex**: 保护了 swap 操作，但没有保护 prog 的读端。

### 8.3 image swap 原子性

`WRITE_ONCE(prog->bpf_func, tmp->bpf_func)` 是 8-byte 原子写，在 x86 上是原子的。在 ARM64 上也是原子的 (aligned 8-byte store)。**原子性正确**。

但问题是: swap 不只是 bpf_func，还包括 25+ 个 aux 字段。这些不是原子更新的。正在执行的 BPF 程序在 swap 过程中可能看到不一致的 aux 数据。不过，执行中的 BPF 程序不会访问 aux 数据 (它们只通过 bpf_func 执行 JIT 代码)，所以这可能是安全的。但 trampoline 回调可能会访问 aux 数据 —— 需要验证。

### 8.4 Verifier bypass

kinsn 的 "双轨制" 验证是最大的 verifier bypass 风险。一个 buggy 的 `emit_x86` 回调可以生成任意代码而 verifier 无法检测。

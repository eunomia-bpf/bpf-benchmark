# BpfReJIT v2 Design Gaps and Concrete Design Recommendations

这份笔记只基于 `vendor/linux-framework/` 内核树。没有读取 `chatgpt-pro-review-20260321.md`。

## 0. Ground Truth: 当前内核树里已经有什么，缺什么

先把“设计设想”和“代码现实”分开，否则后面会把已有基础设施和需要新造的基础设施混在一起。

- 当前树里没有 `BPF_PROG_REJIT` 或 `BPF_PROG_JIT_RECOMPILE` syscall，也没有 `jit_directives.c` / staged JIT swap 框架。`enum bpf_cmd` 在 `vendor/linux-framework/include/uapi/linux/bpf.h:961-995` 结束于 `BPF_PROG_ASSOC_STRUCT_OPS`；`__sys_bpf()` 的 switch 在 `vendor/linux-framework/kernel/bpf/syscall.c:6300-6331` 也没有任何 recompile/rejit 分支。
- 当前树里已经有一半 Inline Kfunc 基础设施，不是从零开始：
  - `KF_INLINE_EMIT` 已定义在 `vendor/linux-framework/include/linux/btf.h:82`。
  - `struct bpf_kfunc_inline_ops` 已定义在 `vendor/linux-framework/include/linux/bpf.h:968-973`。
  - verifier 在 `add_kfunc_call()` 里会把 `KF_INLINE_EMIT` kfunc 解析成 `desc->inline_ops`，见 `vendor/linux-framework/kernel/bpf/verifier.c:3569-3618`。
  - x86_64 JIT 已经在 CALL case 里尝试 `emit_inline_kfunc_call()`，失败时优雅回退到普通 CALL，见 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:579-595` 和 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2463-2471`。

结论：

- `REJIT` 这条线，当前树几乎没有现成 commit/rollback 基础设施，必须新设计。
- `Inline Kfunc` 这条线，当前树已经有注册、查找、x86_64 fallback 机制；需要补的是 verifier-to-JIT metadata、module lifetime、和更清晰的 emitter contract。

## 1. `BPF_PROG_GET_ORIGINAL` 设计

### 1.1 应该保存什么

不应该只保存 `insns`。至少要保存：

- 原始“可重放” bytecode snapshot；
- 对应的 `func_info`；
- 对应的 `line_info`；
- 足够重放 verifier 语义的 load context；
- 一个稳定的 generation/tag 视图。

原因很直接：

- `func_info` 和 `line_info` 在 verifier/JIT 过程中会被改写。`adjust_btf_func()` 会改 `func_info[].insn_off`，见 `vendor/linux-framework/kernel/bpf/verifier.c:19256-19267`；`bpf_adj_linfo()` / `bpf_adj_linfo_after_remove()` 会在插入/删除指令时调整 `linfo`, 见 `vendor/linux-framework/kernel/bpf/core.c:435-453` 和 `vendor/linux-framework/kernel/bpf/verifier.c:22044-22103`。
- `BPF_OBJ_GET_INFO_BY_FD` 当前导出的 `func_info` / `line_info` 直接来自 live `aux->func_info` / `aux->linfo`，见 `vendor/linux-framework/kernel/bpf/syscall.c:5199-5224`。如果不单独保存 original metadata，`GET_ORIGINAL` 只能拿到“已经 fixup 后”的版本。
- 当前 `struct bpf_prog` 里的 `orig_prog` 不能复用。它是 `struct sock_fprog_kern *orig_prog`，是 classic BPF 历史字段，不是 eBPF whole-program snapshot，见 `vendor/linux-framework/include/linux/bpf.h:1811-1818`。

建议新增一个 aux-owned snapshot：

```c
struct bpf_prog_orig_snapshot {
	u32 insn_cnt;
	u32 load_prog_flags;
	u32 attach_btf_id;
	enum bpf_prog_type prog_type;
	enum bpf_attach_type expected_attach_type;
	bool sleepable;
	bool xdp_has_frags;
	bool dev_bound;
	u8 orig_tag[BPF_TAG_SIZE];
	u64 capture_gen;

	/* post-reloc, pre-rewrite internal view */
	struct bpf_insn *insns;

	/* original debug/source mapping */
	struct bpf_func_info *func_info;
	u32 func_info_cnt;
	struct bpf_line_info *line_info;
	u32 nr_line_info;
};
```

不要 deep-copy BTF blob 本体：

- `prog->aux->btf` 和 `prog->aux->attach_btf` 已经是 refcounted kernel object，当前 load/free 路径也已经管理它们，见 `vendor/linux-framework/kernel/bpf/verifier.c:19469-19517` 和 `vendor/linux-framework/kernel/bpf/syscall.c:2378-2387`。
- `GET_ORIGINAL` 返回 `btf_id` / `attach_btf_obj_id` 即可，和 `BPF_OBJ_GET_INFO_BY_FD` 一样，见 `vendor/linux-framework/kernel/bpf/syscall.c:5050-5052` 和 `vendor/linux-framework/kernel/bpf/syscall.c:5199-5201`。

### 1.2 保存时机

最合理的 capture 点不是 `bpf_check()` 之前，也不是 `bpf_check()` 全部结束之后，而是：

- `resolve_pseudo_ldimm64()` 之后；
- 全部 verifier safety checks 通过之后；
- 任何 instruction rewrite 开始之前。

当前 `bpf_check()` 里已经有一个非常清楚的边界注释：`instruction rewrites happen after this point`，见 `vendor/linux-framework/kernel/bpf/verifier.c:26094-26123`。

因此建议在这里 capture original snapshot：

1. `check_btf_info_early()` / `check_btf_info()` 已经把 BTF、func_info、line_info 校验并搬到 aux 里，见 `vendor/linux-framework/kernel/bpf/verifier.c:19469-19517`。
2. `resolve_pseudo_ldimm64()` 已经做完 CO-RE / map/kfunc/BTF relocation，且在这个阶段计算了 tag，见 `vendor/linux-framework/kernel/bpf/verifier.c:21756-21890`。
3. 但 `optimize_bpf_loop()` / dead-code remove / `convert_ctx_accesses()` / `do_misc_fixups()` / `fixup_call_args()` 还没开始，因此 snapshot 仍然是“逻辑上原始”的 program layout，后续不会被 `adjust_btf_func()` / `bpf_adj_linfo()` 污染。

为什么不是 `bpf_check()` 之前：

- 纯 userspace 输入不包含 CO-RE 结果，也不包含 map/BTF/kfunc relocation 结果；
- 之后如果要做 `REJIT`，内核必须再拿回原始 `prog_btf_fd` / `fd_array` / attach fd universe，当前 `bpf_check()` 明确依赖这些 load-time attr，见 `vendor/linux-framework/kernel/bpf/verifier.c:25962-26020` 和 `vendor/linux-framework/kernel/bpf/verifier.c:25449-25479`。

为什么不是 `bpf_check()` 结束之后：

- 那时 `prog->insnsi`、`func_info`、`line_info` 都已经被 fixup/patch 过，不再是 daemon 最想看到的“原始但可重放”的程序。

### 1.3 保存在哪里

建议放在 `struct bpf_prog_aux` 的 main program aux 上，而不是每个 subprog 各放一份：

- 当前内核已经用 `main_prog_aux` 共享 whole-program 资源，见 `vendor/linux-framework/include/linux/bpf.h:1707-1710`。
- `func_info` / `linfo` / `jited_linfo` 本来就是 main/subprog 共享的，见 `vendor/linux-framework/include/linux/bpf.h:1733-1756`。

具体建议：

```c
struct bpf_prog_aux {
	...
	struct mutex rejit_mutex;
	u64 rejit_gen;
	struct bpf_prog_orig_snapshot *orig;
};
```

所有 `GET_ORIGINAL` / `REJIT` 都统一操作 `prog->aux->main_prog_aux->orig`。

### 1.4 内存开销

量级上是可接受的，但应该 opt-in：

- 1000 insns 大约 8 KiB，见 eBPF insn 为 8 bytes 的常规计算；
- `func_info` 的条目数通常是 subprog 数量级，不大；
- `line_info` 可能接近 source-level granularity，开销比 `func_info` 大，但仍远小于 map/value memory。

真正的问题不是“绝对不可接受”，而是“默认给每个 BPF 程序翻倍存一份 xlated snapshot 是否值得”。当前 live program 本身已经保留 `prog->insnsi`、`aux->func_info`、`aux->linfo`，见 `vendor/linux-framework/include/linux/bpf.h:1733-1758` 和 `vendor/linux-framework/include/linux/bpf.h:1814-1818`。`GET_ORIGINAL` 再额外存一份，本质上就是把这组 metadata 复制一遍。

建议：

- 增加 `BPF_F_REJITABLE` load flag；
- 只有带这个 flag 的程序才保存 `orig` snapshot；
- 没带 flag 的程序，`GET_ORIGINAL` / `REJIT` 直接返回 `-EOPNOTSUPP`。

### 1.5 安全和权限

`GET_ORIGINAL` 不能把 post-reloc internal snapshot 原样暴露给用户态，因为 `resolve_pseudo_ldimm64()` 之后指令里已经可能带内核 map pointer / kfunc call imm。

当前内核已经有一套现成的“sanitized dump”逻辑：

- `bpf_insn_prepare_dump()` 会把 map pointer 重新编码成 `map->id + off`，并在无 raw dump 权限时清空 helper/kfunc imm，见 `vendor/linux-framework/kernel/bpf/syscall.c:4903-4955`。
- `BPF_OBJ_GET_INFO_BY_FD` 只有在 `bpf_dump_raw_ok(file->f_cred)` 时才导出完整 raw xlated/jited 程序，见 `vendor/linux-framework/kernel/bpf/syscall.c:5064-5111`。

建议：

- `GET_ORIGINAL` 的权限至少与 raw xlated dump 一致：持有 prog fd，并满足 `bpf_capable()` + `bpf_dump_raw_ok()` 语义；
- 用户态看到的是 sanitized original snapshot；
- 内核内部 reverify 使用的是 unsanitized internal snapshot。

## 2. `BPF_PROG_REJIT` 设计

### 2.1 先说结论：ABI 应该提交“整段新 bytecode”，不是 patch list

建议的 ABI：

```c
struct bpf_prog_rejit_attr {
	__u32 prog_fd;
	__u32 flags;          /* TO_ORIG / TEST_ONLY / NO_COMMIT 等 */
	__u64 expected_gen;   /* compare-and-swap */

	__u32 insn_cnt;
	__aligned_u64 insns;

	__u32 func_info_rec_size;
	__aligned_u64 func_info;
	__u32 func_info_cnt;

	__u32 line_info_rec_size;
	__aligned_u64 line_info;
	__u32 line_info_cnt;

	__u32 log_level;
	__u32 log_size;
	__aligned_u64 log_buf;
};
```

为什么不是 patch list：

- BPF 程序通常不大，整段提交的复制成本很低；
- patch ABI 需要定义 branch retarget、subprog offset、`func_info` / `line_info` 调整、`poke_tab` / `insn_array` 重映射等复杂规则，内核 ABI 很难收敛；
- 当前 verifier/JIT 内部虽然有很多 patch helper，但它们都是内核内部调用约定，不适合直接暴露成用户 ABI，见 `bpf_patch_insn_data()` / `bpf_adj_linfo()` / `adjust_poke_descs()` 相关路径，`vendor/linux-framework/kernel/bpf/verifier.c:21923-22041` 和 `vendor/linux-framework/kernel/bpf/verifier.c:21995-22005`。

建议 v1 直接让 daemon 提交完整 rewritten program。

### 2.2 当前代码现实：没有现成的 staged JIT swap 机制

这点要在论文里写清楚。当前树里：

- 没有 `REJIT` syscall，见 `vendor/linux-framework/include/uapi/linux/bpf.h:961-995` 和 `vendor/linux-framework/kernel/bpf/syscall.c:6300-6331`；
- `struct bpf_prog_aux` 里也没有 `jit_recompile_mutex` / staged image state，见 `vendor/linux-framework/include/linux/bpf.h:1668-1776`；
- x86 JIT 只有 normal compile/free 路径，没有“在同一个 live prog 上 staged commit/abort”的 arch state，见 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3720-3930` 和 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3959-4012`。

因此 `REJIT` 不是“复用现成 staged swap”，而是要新增一套。

### 2.3 v1 必须收紧的 reverify contract

如果不收紧，内核实现会立刻爆炸。

建议 v1 强制：

- 同一个 `struct bpf_prog` 身份，不换 prog id，不换 fd，不换 attach/link 对象；
- `prog->type`、`expected_attach_type`、`sleepable`、`xdp_has_frags`、`attach_btf` / `attach_btf_id`、token privilege mode 必须不变；
- map / BTF / kfunc 外部依赖 universe 必须完全相同；
- 不支持新 map、新 BTF、新 kfunc、新 module-BTF offset；
- 不支持 offload 程序；
- 不支持 `prog_array_member_cnt != 0` 的程序；
- 不支持使用 `BPF_MAP_TYPE_INSN_ARRAY` 的程序；
- 不支持 live `struct_ops` 程序。

为什么“外部依赖 universe 必须完全相同”，而不是“允许 subset”：

- `bpf_check()` 现在依赖 load-time `fd_array` 和 `prog_btf_fd`，见 `vendor/linux-framework/kernel/bpf/verifier.c:25449-25479` 和 `vendor/linux-framework/kernel/bpf/verifier.c:19469-19517`；
- `BPF_PROG_BIND_MAP` 还允许 load 之后继续向 `used_maps` 追加 map，见 `vendor/linux-framework/kernel/bpf/syscall.c:6047-6102`；
- 如果允许 map/kfunc set 变化，`used_maps` / `used_btfs` / `kfunc_btf_tab` / module refs / info dump 全都要做 epoch-based swap 和回收，复杂度陡增。

v1 用“exact same extern universe”最稳妥。

### 2.4 内核处理流程：不要硬复用 `bpf_check()`，要做 internal replay mode

`bpf_check()` 不能原样拿来做 live reverify，原因不是 verifier 本身不行，而是它强依赖 load-time `union bpf_attr`：

- `bpf_vlog_init()` 直接吃 `attr->log_*`，见 `vendor/linux-framework/kernel/bpf/verifier.c:25962-25967`；
- `process_fd_array()` 直接扫描 `attr->fd_array`，见 `vendor/linux-framework/kernel/bpf/verifier.c:25968-25970` 和 `vendor/linux-framework/kernel/bpf/verifier.c:25449-25479`；
- `check_btf_info_early()` / `check_btf_info()` 直接吃 `attr->prog_btf_fd`、func/line info userspace buffer，见 `vendor/linux-framework/kernel/bpf/verifier.c:19469-19517`；
- `resolve_pseudo_ldimm64()` 依赖 `env->fd_array` 解析 map/BTF/kfunc fd，见 `vendor/linux-framework/kernel/bpf/verifier.c:21756-21890`。

建议新增内部入口，例如：

```c
int bpf_check_rejit(struct bpf_prog **cand,
		    const struct bpf_prog_orig_snapshot *orig,
		    const struct bpf_prog_rejit_input *in,
		    struct bpf_verifier_log *log);
```

它做三件事：

1. 从 `orig` 和 live prog 复制 verifier context，而不是从 `union bpf_attr` 取 fd；
2. 校验用户提交的新 `func_info` / `line_info` 是否仍然匹配同一个 `aux->btf`；
3. 在“同一 extern universe”约束下重跑 verifier 和 subprog/JIT 准备逻辑。

### 2.5 推荐的 commit flow

1. `bpf_prog_get(prog_fd)` 拿 live 引用，避免 unload race。当前大量 syscall 都是这个模式，见 `vendor/linux-framework/kernel/bpf/syscall.c:4701-4724` 和 `vendor/linux-framework/kernel/bpf/syscall.c:6047-6102`。
2. 拿 `main_aux->rejit_mutex`，并检查 `expected_gen`。
3. 分配 fresh candidate `struct bpf_prog`，使用 `bpf_prog_alloc_no_stats()`，这样可以继承标准 JIT/blinding 初始状态，见 `vendor/linux-framework/kernel/bpf/core.c:101-145`。
4. 把 live prog 的 immutable context 复制到 candidate：
   - `type` / `expected_attach_type` / `sleepable`；
   - `aux->attach_btf` / `attach_btf_id` / `attach_func_proto`；
   - `aux->token`；
   - `aux->xdp_has_frags` / `dev_bound`；
   - `aux->saved_dst_*` 之类 attach context。
5. 用 `bpf_check_rejit()` 验证 candidate。
6. 走标准 `bpf_int_jit_compile()` 和 `bpf_prog_lock_ro()`，这样常量 blinding、subprog JIT、`jited_linfo`、`extable`、private stack 都沿用现有后端逻辑，见 `vendor/linux-framework/kernel/bpf/core.c:2540-2570`，`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3720-3930`。
7. 进入 commit phase：把 live `struct bpf_prog` 的“执行态字段”原地替换为 candidate 的字段。
8. 重建 trampoline / tailcall / ksym / perf 可见性。
9. `synchronize_rcu()` 后释放旧 image 和旧 metadata。

### 2.6 为什么必须“保留同一个 `struct bpf_prog` 身份”

因为现有内核很多地方直接持有 `struct bpf_prog *`，不是通过间接层访问：

- `BPF_MAP_TYPE_PROG_ARRAY` 直接把 `bpf_prog_get(fd)` 得到的 `struct bpf_prog *` 放进 map value，见 `vendor/linux-framework/kernel/bpf/arraymap.c:963-994`；
- `prog_array_member_cnt` 也是直接挂在 callee `prog->aux` 上，见 `vendor/linux-framework/include/linux/bpf.h:1696-1700` 和 `vendor/linux-framework/kernel/bpf/arraymap.c:963-1005`；
- link/trampoline/perf attach 路径普遍都以 `struct bpf_prog *` 为对象。

如果 `REJIT` 通过“换整个 `struct bpf_prog` 指针”来实现，那么 prog array、link、attach state、fd 都要全局重绑，这基本不可行。

所以正确的方向是：保留 live `struct bpf_prog` 身份，只替换其 code image 和与 code image 严格绑定的 metadata。

### 2.7 需要 swap 的字段

至少包括：

- `prog->len` / `prog->insnsi` / `prog->tag`；
- `prog->bpf_func` / `prog->jited_len` / `prog->jited`；
- `aux->func` / `func_cnt` / `real_func_cnt`；
- `aux->extable` / `num_exentries`；
- `aux->jited_linfo` / `aux->linfo` / `aux->func_info`；
- `aux->kfunc_tab` / `aux->kfunc_btf_tab`；
- `aux->poke_tab` / `size_poke_tab`；
- `aux->priv_stack_ptr`；
- `aux->bpf_exception_cb` / `exception_boundary`。

这些字段当前要么由 verifier 重写，要么由 JIT 后端填充，见：

- `vendor/linux-framework/kernel/bpf/verifier.c:22930-23145`；
- `vendor/linux-framework/kernel/bpf/verifier.c:26134-26167`；
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3880-3911`；
- `vendor/linux-framework/include/linux/bpf.h:1707-1768`。

### 2.8 并发控制

建议新增：

```c
struct bpf_prog_aux {
	...
	struct mutex rejit_mutex;
	u64 rejit_gen;
};
```

语义：

- 每个 main program 只能串行 `REJIT`；
- `expected_gen` 形成 compare-and-swap；
- `GET_ORIGINAL` / `BPF_OBJ_GET_INFO_BY_FD` 复制 mutable metadata 时也拿这把锁，避免 `func_info` / `linfo` / `insnsi` swap 时的 UAF。

当前 `BPF_OBJ_GET_INFO_BY_FD` 假设这些 aux 指针是 immutable 的，直接 copy 出去，没有任何锁，见 `vendor/linux-framework/kernel/bpf/syscall.c:5199-5224`。一旦引入 `REJIT`，这一点必须改。

### 2.9 回滚

建议支持两类回滚：

- soft rollback：verify/JIT 失败则完全不 commit，返回 verifier log；
- hard rollback：daemon 发现线上异常后，以 `BPF_F_REJIT_TO_ORIG` 重新切回 `orig` snapshot。

后者不应该要求 daemon 再把 original bytecode 传回来，因为内核已经保存了 `orig` snapshot。

## 3. Inline Kfunc：当前基础设施已经在哪一步，缺什么

### 3.1 当前已经到哪一步

Inline Kfunc 不是纯设想，当前树已经具备：

- flag：`KF_INLINE_EMIT`，见 `vendor/linux-framework/include/linux/btf.h:82`；
- 注册接口：`bpf_register_kfunc_inline_ops()` / `bpf_unregister_kfunc_inline_ops()`，见 `vendor/linux-framework/include/linux/bpf.h:3043-3051` 和 `vendor/linux-framework/kernel/bpf/verifier.c:3240-3293`；
- verifier side binding：`add_kfunc_call()` 会把 `KF_INLINE_EMIT` kfunc 解析成 `desc->inline_ops`，见 `vendor/linux-framework/kernel/bpf/verifier.c:3569-3618`；
- x86_64 JIT side use：CALL case 里对 `BPF_PSEUDO_KFUNC_CALL` 先尝试 `emit_inline_kfunc_call()`，失败时回退成普通 CALL，见 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2463-2471`；
- fallback 语义已经很合理：`emit_inline_kfunc_call()` 找不到 emitter 时返回 `-ENOENT`，CALL case 继续走普通 CALL，见 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:579-595`。

因此，论文里不应该把 Inline Kfunc 写成“完全新发明”，而应该写成“把现有 per-kfunc inline hook 补成完整 ISA-extension 机制”。

### 3.2 当前 emitter interface 的不足

当前接口是：

```c
struct bpf_kfunc_inline_ops {
	int (*emit_x86)(u8 *image, u32 *off, bool emit,
			const struct bpf_insn *insn,
			struct bpf_prog *prog);
	int max_emit_bytes;
};
```

见 `vendor/linux-framework/include/linux/bpf.h:968-973`。

它的不足非常明显：

- 只有 x86，没有 arch-generic 层；
- 只拿到 `insn` 和 `prog`，拿不到 verifier 证明出来的 per-callsite facts；
- 没有 clobber contract；
- 没有 module owner pinning；
- 没有关于 stack alignment、may-fault、extable、tailcall context、private frame 的上下文。

### 3.3 “Verifier 零改动”并不完全成立

如果所谓“零改动”指的是“不改 `check_kfunc_call()` 的 policy path”，这个可以做到。

但如果指的是“完全不改 verifier plumbing”，不成立。

原因：

- verifier 确实已经为某些特殊 kfunc 保存了少量 aux 信息，比如 `kptr_struct_meta`、`insert_off`、`obj_new_size`、`arg_prog`，并在 `fixup_kfunc_call()` 中消费，见 `vendor/linux-framework/include/linux/bpf_verifier.h:525-574` 和 `vendor/linux-framework/kernel/bpf/verifier.c:23165-23317`。
- 但是 `struct bpf_kfunc_call_arg_meta` 里的常量信息是临时态，只支持一份 `arg_constant`，见 `vendor/linux-framework/kernel/bpf/verifier.c:309-353`。
- `check_kfunc_args()` 虽然会检查 `is_kfunc_arg_constant()` 并记录 `meta->arg_constant.value`，但这个值不会持久化到 prog aux 给 JIT 使用，见 `vendor/linux-framework/kernel/bpf/verifier.c:13367-13397`。

所以结论是：

- verifier policy 可以继续走 `check_kfunc_call()`；
- 但必须新增 verifier-to-JIT 持久化 metadata，把 per-callsite 常量/属性导出给 emitter。

### 3.4 建议的 callsite metadata

建议新增：

```c
struct bpf_kfunc_inline_callsite {
	u32 insn_idx;
	u8 nr_args;
	u8 const_mask;
	u8 arg_prog_reg;
	bool non_sleepable;
	u64 const_arg[5];
};
```

填充来源：

- formal arg count/size 继续来自 `btf_func_model`，当前已有 `bpf_jit_find_kfunc_model()`，见 `vendor/linux-framework/kernel/bpf/verifier.c:3583-3599`；
- verifier 证明出的常量参数、`arg_prog`、`non_sleepable` 从 `check_kfunc_call()` / `insn_aux_data` 导出。

### 3.5 callee-saved registers 和 emitter contract

x86_64 BPF JIT 的寄存器约定是固定的：

- `R6-R9` 映射到 `RBX/R13/R14/R15`，都是 callee-saved，见 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:172-193`；
- `R10` 是 BPF temp / blinding register；
- `R11` / `R12` 有各自的 JIT 内部用途。

因此 v1 必须明确：

- emitter 只能生成 leaf inline sequence；
- 不能发出额外 call；
- 不能破坏 `RBX/R13/R14/R15/RBP`；
- 如需 scratch，只能使用 JIT 允许的 caller-clobbered 寄存器；
- 如需 may-fault memory access，必须显式声明并走 extable helper，否则禁止。

更好的接口形状应该是：

```c
struct bpf_kfunc_inline_ops {
	struct module *owner;
	int (*emit_x86)(struct bpf_jit_emit_ctx *ctx,
			const struct bpf_kfunc_inline_callsite *meta);
	u32 clobber_mask;
	u32 flags;
	int max_emit_bytes;
};
```

### 3.6 module unload 现在是个真空区

当前 `bpf_register_kfunc_inline_ops()` 只把 `ops` 指针挂在一个全局 list 上，没有 owner pinning，见 `vendor/linux-framework/kernel/bpf/verifier.c:3210-3293`。

而 kfunc 的 module-BTF lifetime 这边，内核已经有一套正确做法：

- `__find_kfunc_desc_btf()` 对 module BTF 做 `btf_try_get_module()`，并把 `{btf,module,offset}` 存进 `kfunc_btf_tab`，见 `vendor/linux-framework/kernel/bpf/verifier.c:3324-3387`；
- free 时 `bpf_free_kfunc_btf_tab()` 会 `module_put()` / `btf_put()`，见 `vendor/linux-framework/kernel/bpf/verifier.c:3389-3401`。

Inline emitter 应该照这个模式做一套 owner pinning：

- `bpf_register_kfunc_inline_ops()` 注册时记录 `owner`；
- verifier 在把 `inline_ops` 绑定进 `kfunc_desc` 时 `try_module_get(owner)`；
- prog free / old-state reclaim 时 `module_put(owner)`。

否则：

- module 在 prog 生命周期内 unload，`desc->inline_ops` 会悬空；
- 后续 REJIT 或二次 JIT pass 会 UAF。

### 3.7 tail call / bpf-to-bpf interaction

当前 x86_64 inline path 只是“在普通 CALL lowering 之前尝试插入机器码”，见 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2463-2471`。

这意味着 v1 应该明确限制：

- inline kfunc 不能再发出 tail call；
- inline kfunc 不能引入新的 bpf-to-bpf edge；
- inline kfunc 不能依赖 JIT 的 call-depth accounting；
- inline kfunc 不能要求 verifier/JIT 重新计算 subprog call graph。

换句话说，v1 的 Inline Kfunc 应该是“leaf machine-code expansion”，不是“任意自定义 mini-subprogram”。

## 4. Correctness Story：不能只说“userspace 负责 correctness”

这句话太弱。论文至少要给出一个 operational discipline。

### 4.1 建议的 correctness protocol

1. daemon 通过 `GET_ORIGINAL` + `BPF_OBJ_GET_INFO_BY_FD` 取到 original snapshot、current info、`rejit_gen`。
2. daemon 做 rewrite，但必须先通过 structural guard：
   - attach context 不变；
   - extern universe 相同；
   - prog type / sleepable / xdp flags 不变。
3. 如果 prog type 支持 `BPF_PROG_TEST_RUN`，则对 original/candidate 跑相同输入做 differential test。
4. 成功后用 `expected_gen` 发起 `REJIT`。
5. daemon 记录新的 generation baseline。
6. 持续监控性能/异常指标。
7. 超阈值则 `REJIT_TO_ORIG`。

### 4.2 Differential testing 不是 universal

`BPF_PROG_TEST_RUN` 当前只是调用 `prog->aux->ops->test_run`；如果这个回调不存在，直接 `-ENOTSUPP`，见 `vendor/linux-framework/kernel/bpf/syscall.c:4701-4724`。

所以论文不能暗示“所有 prog type 都能先 test-run 再替换”。正确说法应该是：

- 对支持 `test_run` 的 prog type：做 differential testing；
- 对不支持的 prog type：只能做 canary rollout / shadow execute / attach-point-specific validation；
- 因此 BpfReJIT 的 correctness story 是 tiered，而不是 uniform。

### 4.3 Gradual rollout 的正确粒度

当前内核没有“同一个 prog 内部按流量比例切分 original/new image”的机制。

所以 rollout 粒度只能是：

- 程序实例级；
- attach-point 级；
- 或同类程序子集级。

不能写成“对一个 live prog 先放 1% 流量到优化版”这种像 userspace service mesh 的话术，除非你另做 shadow dispatcher。

### 4.4 Auto-rollback 需要 generation-aware metrics

当前 `BPF_OBJ_GET_INFO_BY_FD` 已导出：

- `run_time_ns`
- `run_cnt`
- `recursion_misses`

见 `vendor/linux-framework/kernel/bpf/syscall.c:5045-5050`。

但这些 runtime stats 的更新并不是无条件开启的；fast path 受 `bpf_stats_enabled_key` 控制，见 `vendor/linux-framework/include/linux/filter.h:688-716`，而用户态需要先通过 `BPF_ENABLE_STATS(BPF_STATS_RUN_TIME)` 打开统计，见 `vendor/linux-framework/kernel/bpf/syscall.c:6001-6034` 和 `vendor/linux-framework/include/uapi/linux/bpf.h:1481`。

但这些计数是“同一个 `struct bpf_prog` 累积计数”。如果 `REJIT` 保持 prog identity，不引入 generation 概念，daemon 就只能自己记“提交时基线”，不能直接从内核看到“这一代 image”的 delta。

建议至少新增：

```c
struct bpf_prog_info {
	...
	__u64 rejit_gen;
	__u64 last_rejit_ns;
};
```

这样 daemon 才能把 `run_cnt` / `run_time_ns` 做 generation-scoped 差分。

### 4.5 Certificate/proof 的合理位置

我不建议把 certificate checker 放进内核。那会把 `REJIT` 变成第二 verifier。

合理做法是：

- daemon 为每一类 transformation 生成 transformation-specific certificate；
- 例如 peephole algebraic rewrite、inline-kfunc substitution、constant folding，各自有不同证书格式；
- 论文里把它定义为“optional correctness discipline”，不是 kernel-enforced safety mechanism。

这类证书最适合做成：

- daemon 内部的审计 artifact；
- 或配合 CI / offline validator；
- 未来工作再考虑 machine-checked checker。

## 5. 安全模型

### 5.1 daemon 权限

如果 daemon 要自己发现所有程序，当前内核权限模型基本逼着它拥有：

- `CAP_SYS_ADMIN`：因为 `BPF_PROG_GET_FD_BY_ID` 要求它，见 `vendor/linux-framework/kernel/bpf/syscall.c:4814-4824`；
- `CAP_BPF`：因为 raw dump / program management / privileged BPF 操作都围绕它；
- 通常还需要 perf 权限，如果要订阅 BPF load/unload perf event。

如果不是“系统级 daemon”，而是“调用方自己把 prog fd 交给 daemon”，那 `CAP_SYS_ADMIN` 可以弱化；但默认 deployment story 仍然是 host-level privileged service。

### 5.2 daemon 被攻破后的能力边界

最坏情况：

- 它能把已授权的 BPF 程序改成恶意逻辑；
- 它能关闭某些安全检查；
- 它能让程序更慢、更多 map access、更多 telemetry leakage；
- 它能用 `REJIT_TO_ORIG`/反复 REJIT 制造性能抖动。

但它不能：

- 绕过 verifier；
- 直接任意写内核内存；
- 像任意 kernel module 那样执行 unrestricted native code。

这和现有 BPF 安全模型相比，新增的风险不是“kernel memory safety”，而是“post-load semantic mutability”。

### 5.3 和 kernel module 安全模型的差别

普通 `REJIT` 的风险明显低于 kernel module：

- verifier 仍然卡住 memory safety / type safety；
- JIT 后端仍然是固定 arch JIT。

但 Inline Kfunc emitter module 更接近 kernel module 风险，因为：

- emitter 在 JIT 期间直接生成 native code；
- 如果 emitter bug 了，可能 miscompile；
- 当前 inline-ops 注册接口还没有 owner pinning 和强 contract。

因此建议：

- REJIT daemon 可以是 runtime-privileged component；
- Inline emitter 最好限制为 built-in 或 signed module；
- 论文里把两者的 trust boundary 分开写。

## 6. Daemon 设计

### 6.1 发现新程序：推荐 perf BPF event，不推荐 ring buffer

当前内核没有“BPF 程序 load/unload 的 ring buffer 通知 API”。

现有两个现实选项：

- 轮询 `BPF_PROG_GET_NEXT_ID` / `BPF_PROG_GET_FD_BY_ID`；
- 订阅 perf BPF load/unload event。

perf 路径更好，因为内核已经在 load/unload 时发事件：

- `perf_event_bpf_event(prog, PERF_BPF_EVENT_PROG_LOAD, 0)`，见 `vendor/linux-framework/kernel/bpf/syscall.c:3120`；
- `perf_event_bpf_event(prog, PERF_BPF_EVENT_PROG_UNLOAD, 0)`，见 `vendor/linux-framework/kernel/bpf/syscall.c:2405`；
- perf event core 还会同时发 BPF ksymbol 事件，见 `vendor/linux-framework/kernel/events/core.c:10256-10289`。

所以 discovery 推荐顺序：

1. perf BPF events 订阅；
2. 进程启动时全量扫一遍现有 prog id；
3. 定期低频 rescan 补漏。

### 6.2 Profiling 数据源

最低配：

- `run_cnt` / `run_time_ns` / `recursion_misses`，见 `vendor/linux-framework/kernel/bpf/syscall.c:5045-5050`。

前提是 daemon 已经打开 runtime stats；否则这些字段可能长期接近零或没有代表性，见 `vendor/linux-framework/include/linux/filter.h:688-716` 和 `vendor/linux-framework/kernel/bpf/syscall.c:6001-6034`。

更强的数据源：

- perf sample + BPF ksymbol 地址归因；
- attach-point-specific map metrics；
- branch miss / LLC miss 之类 PMU 数据，但那已经超出 generic BPF API。

### 6.3 决策引擎

建议不要“看见程序就优化”。至少要有：

- warmup threshold：`run_cnt` 达到阈值再考虑；
- allowlist / denylist；
- 只对已知 transform family 生效；
- generation-aware rollback guard；
- 对 tracing/LSM 这类无 `test_run` 的类型默认更保守。

### 6.4 变换管道

推荐管道：

1. discovery
2. profile
3. select candidate prog
4. pull original snapshot
5. rewrite
6. structural guard
7. differential test if supported
8. apply with `expected_gen`
9. monitor
10. rollback if needed

### 6.5 可配置性和系统集成

最小可行配置项：

- prog type / attach type allowlist；
- prog name / BTF id match 规则；
- blacklist map ids / kfunc ids；
- 是否允许 Inline Kfunc；
- 是否要求 test_run 通过；
- rollback 阈值。

部署上：

- systemd service 比较自然；
- Kubernetes 场景更像 host-level DaemonSet，而不是 pod-sidecar，因为 BPF 生命周期是 host-wide 的。

## 7. 容易漏掉但必须回答的技术问题

### 7.1 tail call：这是当前方案最大的透明性缺口

当前内核只跟踪“哪个 caller 程序使用了哪个 prog array map 的 direct tail call patch site”：

- `struct bpf_array_aux` 里有 `poke_progs` 和 `poke_mutex`，见 `vendor/linux-framework/include/linux/bpf.h:1814-1818`；
- `prog_array_map_poke_track()` / `prog_array_map_poke_run()` 维护并更新这些 patch site，见 `vendor/linux-framework/kernel/bpf/arraymap.c:1050-1152`。

但当前内核没有反向跟踪“某个 callee prog 现在在哪些 prog array 里”：

- `prog_fd_array_get_ptr()` / `prog_fd_array_put_ptr()` 只维护了一个计数 `prog_array_member_cnt`，见 `vendor/linux-framework/kernel/bpf/arraymap.c:963-1005`；
- `struct bpf_prog_aux` 里也只有这个计数字段，没有 reverse membership list，见 `vendor/linux-framework/include/linux/bpf.h:1696-1700`。

这意味着：

- 如果 callee prog 原地换了 `bpf_func`，现有 direct tail call patch site 不会自动更新；
- 而且你甚至不知道该去通知哪些 prog array map。

我的建议很明确：

- prototype v1 直接拒绝 `prog->aux->prog_array_member_cnt != 0` 的程序；
- 如果要支持，就必须新增 per-prog reverse membership list，把“哪些 prog array 含有这个 prog”记录下来，并在 commit 时逐个 map `map_poke_run()`。

这是 deal-breaker 级别问题，不是实现细节。

### 7.2 trampoline：可以支持，但要明确边界

当前内核已经有：

- `bpf_prog_has_trampoline()` 判断 tracing/LSM 程序是否有 trampoline，见 `vendor/linux-framework/kernel/bpf/trampoline.c:137-149`；
- `bpf_prog_regenerate_trampolines()` 可以基于 old `bpf_func` 重新 retarget/update trampoline，见 `vendor/linux-framework/kernel/bpf/trampoline.c:905-962`。

所以 tracing/LSM/freplace 这条线不是 blocker。

但要明确：

- `struct_ops` 不在 `bpf_prog_has_trampoline()` 的覆盖里；
- v1 最安全的策略是 reject live `struct_ops`。

### 7.3 ksym 和 perf ksymbol：必须一起更新

当前程序 load/unload 做了两层可见性更新：

- kallsyms 树：`bpf_prog_kallsyms_add()` / `bpf_prog_kallsyms_del()`，见 `vendor/linux-framework/kernel/bpf/core.c:669-705`；
- perf ksymbol：`perf_event_bpf_event(...PROG_LOAD/UNLOAD...)`，见 `vendor/linux-framework/kernel/bpf/syscall.c:2405` / `3120` 和 `vendor/linux-framework/kernel/events/core.c:10256-10289`。

但当前树里没有 `bpf_prog_kallsyms_replace()` 一类 helper。

所以 `REJIT` commit 必须显式做：

1. perf unregister old image；
2. kallsyms del old image；
3. swap image；
4. kallsyms add new image；
5. perf register new image。

否则：

- `/proc/kallsyms` 地址会旧；
- perf 对 JIT image 的地址归因会旧；
- daemon 用 PMU/perf 做 rollout 监控会看错地址。

### 7.4 perf event attach 本身不需要重绑，但 perf attribution 需要更新

如果某个 BPF 程序是挂在 perf_event hook 上，attachment 对象持有的是 prog identity，不是旧 image address；只要保留同一个 `struct bpf_prog`，attach 本身不需要重绑。

真正要更新的是：

- BPF ksymbol/perf 地址归因；
- 任何缓存 JIT image address 的观测端。

### 7.5 `bpf_prog_pack` / old image 回收

x86 JIT 当前通过 `bpf_jit_binary_pack_*` 和 `x64_jit_data` 管理 JIT image，见 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3750-3890` 和 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3971-3975`。

因此 `REJIT` commit 必须：

- 先让 new image 完整生成并 finalized；
- old image 不能立刻 free；
- 必须等 trampoline/tailcall/RCU grace period 之后再回收 old pack header / private stack / extable。

### 7.6 constant blinding 不是 blocker，但实现上必须走标准 JIT 路径

当前 `bpf_prog_alloc_no_stats()` 会设置 `blinding_requested = bpf_jit_blinding_enabled(fp)`，见 `vendor/linux-framework/kernel/bpf/core.c:123-126`。

x86 JIT compile 时会先尝试 `bpf_jit_blind_constants()`，见 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3734-3744`。

所以 `REJIT` 不应该“手写一个只换 image 的 fast path”，而应该对 candidate 走标准 `bpf_int_jit_compile()`。这样 blinding 行为自然保持一致。

### 7.7 `BTF` / `func_info` / `line_info`

当前 live info dump 直接导出 `aux->func_info` / `aux->linfo`，见 `vendor/linux-framework/kernel/bpf/syscall.c:5199-5224`。

因此：

- `GET_ORIGINAL` 需要 original snapshot 自己保存一份 original `func_info` / `line_info`；
- `REJIT` commit 后如果希望 `bpftool prog dump` 仍然可读，就必须把 current `func_info` / `line_info` 也一并换成新版本；
- `BPF_OBJ_GET_INFO_BY_FD` 需要和 `REJIT` 同步，不能再假设这些指针 immutable。

### 7.8 `BPF_MAP_TYPE_INSN_ARRAY`

这类 map 绑定的是“xlated insn offset 到 jited ip”的映射，当前 verifier/JIT 在 load 期间会：

- `bpf_insn_array_init()` 初始化；
- rewrite 时 `bpf_insn_array_adjust()` / `adjust_after_remove()`；
- load 完成时 `bpf_prog_mark_insn_arrays_ready()` 检查 `ips[]` 全部就绪。

见：

- `vendor/linux-framework/kernel/bpf/bpf_insn_array.c:178-259`
- `vendor/linux-framework/kernel/bpf/verifier.c:21969-21993`
- `vendor/linux-framework/kernel/bpf/syscall.c:2851-2867`

`REJIT` 改变 instruction layout 后，这套 offset/ip 映射必须整体刷新。

除非你愿意在 v1 一起把它做好，否则建议直接 reject “使用了 `BPF_MAP_TYPE_INSN_ARRAY` 的 prog”。

### 7.9 program tag

当前 `bpf_prog_calc_tag()` 在 `resolve_pseudo_ldimm64()` 阶段计算 tag，见 `vendor/linux-framework/kernel/bpf/verifier.c:21877` 和 `vendor/linux-framework/kernel/bpf/core.c:301-337`；`BPF_OBJ_GET_INFO_BY_FD` 会导出 `prog->tag`，见 `vendor/linux-framework/kernel/bpf/syscall.c:5021`。

因此 `REJIT` commit 后应同时维护：

- `orig_tag`：来自 original snapshot；
- `current_tag`：来自 candidate reverify。

否则 daemon 无法用 tag 标识“这是哪一代 image”。

## 8. 建议的 v1 scope

如果目标是把原型做出来并让论文论证站得住，我建议把 v1 scope 收紧到：

- x86_64 only；
- JITed eBPF only；
- non-offload；
- `BPF_F_REJITABLE` opt-in only；
- exact same extern universe；
- no `prog_array_member_cnt`；
- no `BPF_MAP_TYPE_INSN_ARRAY`；
- no live `struct_ops`；
- Inline Kfunc 仅支持 leaf emitter，不支持外部 call / tail call / may-fault。

这个 scope 不漂亮，但它把真正的 blocker 收敛到一小撮。

## 9. Prioritized Gap List

### 9.1 论文里必须回答

1. original snapshot 的精确定义与 capture 点。
   - 必须明确是 post-reloc, pre-rewrite, post-verification，而不是模糊地说“原始 bytecode”。
2. live reverify 的 contract。
   - 必须说明不能直接复用 raw `bpf_check()`，需要 internal replay mode。
3. identity-preserving commit 机制。
   - 必须说明为什么不能换 `struct bpf_prog *`，以及 commit 时要换哪些字段。
4. tailcall / trampoline / ksym / perf 同步。
   - 这不是工程细节，是透明性成立与否的核心。
5. correctness protocol 的边界。
   - `test_run` 不是 universal；rollout 是 program-level，不是 request-level。
6. 安全模型。
   - daemon 的权限、失陷后能力边界、Inline emitter module 的额外风险，必须写清楚。

### 9.2 可以作为 future work

1. patch-based ABI；
2. subset/new extern universe；
3. richer certificates / machine-checked proofs；
4. 多架构 Inline Kfunc emitter；
5. finer-grained rollout/shadow execution；
6. 对 offload/struct_ops/insn_array/full tailcall membership 的完整支持。

### 9.3 Deal-breakers

1. 如果不能解决“同一 `struct bpf_prog` 身份下的安全 image swap”，方案不成立。
2. 如果不能解决 tailcall callee image 更新后的 reverse repoke，且又不把 `prog_array_member_cnt != 0` 排除掉，方案不成立。
3. 如果 reverify 不能保留原始 verifier privilege/attach/external-universe 语义，而只是“让特权 daemon 重新 load 一遍”，方案不成立。
4. 如果 Inline Kfunc emitter 没有 owner pinning 和 verifier-to-emitter metadata，只能做几个 ad-hoc special case，不能称为完整 ISA-extension story。

## 10. Bottom Line

BpfReJIT v2 的大方向是成立的，但 current story 里最缺的不是“更多 use case”，而是三个 engineering truth：

- `GET_ORIGINAL` 必须是一个精确定义的 post-reloc/pre-rewrite snapshot，而不是模糊的“保存原始字节码”；
- `REJIT` 的核心难点不是 verifier，而是保留 prog identity 的 image/meta swap，以及 tailcall/trampoline/ksym/perf 周边同步；
- Inline Kfunc 在这棵树里已经有一半实现，真正缺的是 metadata plumbing、module lifetime 和 emitter contract。

如果论文把这三个点讲实，方案会从“直觉上很优雅”变成“工程上可实现且边界清楚”。

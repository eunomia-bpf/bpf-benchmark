# kinsn_ops 完整设计

日期：2026-03-23
状态：设计文档，不包含实现代码

## 0. 结论摘要

### 0.1 推荐总体方案

推荐把 kinsn 定义为一个独立的 sidecar 行为对象：`struct bpf_kinsn_ops`。

- kinsn 仍然首先是一个 kfunc：可见性、allowlist、BTF 原型、prog_type 绑定仍由 `btf_kfunc_id_set` 管。
- kinsn 额外再绑定一份 `bpf_kinsn_ops`：JIT emit 和 verifier modeling 都挂在这里。
- verifier 和 JIT 都只看 `bpf_kfunc_desc->kinsn_ops`，不再出现旧命名。
- 不推荐把 JIT/verifier 回调直接塞进 `btf_kfunc_id_set`；也不推荐伪造一个“base kfunc struct”再做嵌入，因为内核里根本没有一等公民的 `struct bpf_kfunc` 可供继承。

### 0.2 对当前提议的关键修正

1. 不能把 `insn->off` 直接拿来给 module kinsn 编操作数。

- 对 module kfunc，`off` 现在就是 module BTF 在 `fd_array` 中的索引。
- `find_kfunc_desc_btf()`、`fetch_kfunc_meta()`、`bpf_kfunc_desc` 的 key、以及 disasm 都依赖这个 `off`。
- daemon 也明确为每个 kfunc 维护 module BTF FD，并在 `fd_array` 里传给 REJIT。

结论：`dst_reg/off` 直接编码操作数的方案，不适合作为当前 module kinsn 的推荐主方案。

2. “KF_INLINE_EMIT 只 clobber r0”是错的。

- 当前 `module/x86/bpf_rotate.c` 的 emit 会写 `RCX`，对应 BPF 的 `r4`。
- 所以 verifier 不能只做 “preserve r1-r5”；必须允许 per-kinsn、甚至 per-call 的 clobber 建模。

3. `clobber_mask + narrow_result()` 这两个零散字段不够。

- `clobber_mask` 对 packed/in-place kinsn 往往是动态的。
- `narrow_result()` 只做返回值范围收窄，不足以表达输入寄存器、内存访问、副作用和 32-bit subreg 语义。

结论：需要一个统一的 verifier effect callback，而不是继续给旧 `bpf_kfunc_inline_ops` 打补丁。

### 0.3 分阶段推荐

推荐分 2 层：

1. `kinsn_ops` 核心层，主推 upstream

- 统一 `bpf_kinsn_ops`
- verifier 支持精确 clobber / result modeling / memory effect
- 保留标准 kfunc 调用 ABI 作为默认兼容模式

2. packed operand ABI，作为后续扩展

- 不复用 `off`
- 如确实要做零额外 BPF 指令的编码，使用独立 sidecar/pseudo-insn 载荷
- 不把 packed ABI 和核心 `kinsn_ops` 绑死

这样可以先解决 780+ skip 和 verifier precision 问题，再单独推进“1 条 BPF insn 编码一个 kinsn”的性能 ABI。

## 1. 现状约束

### 1.1 当前内核路径

当前内核里已经有一个最小的 “kinsn” 机制：

- `struct bpf_kfunc_inline_ops` 定义在 `vendor/linux-framework/include/linux/bpf.h:968-977`
- `bpf_register_kfunc_inline_ops()` / `bpf_unregister_kfunc_inline_ops()` 定义在 `vendor/linux-framework/kernel/bpf/verifier.c:3240-3290`
- `bpf_kfunc_desc` 缓存 `inline_ops` 指针，见 `vendor/linux-framework/kernel/bpf/verifier.c:3173-3180`
- `add_kfunc_call()` 在 verifier 早期把 `inline_ops` 填到 `desc`，见 `vendor/linux-framework/kernel/bpf/verifier.c:3522-3613`
- x86 JIT 在 `emit_kinsn_call()` 中按 `insn` 查 `kinsn_ops` 并调用 emit，见 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:579-599`

但 verifier 侧完全按普通 kfunc 处理：

- `check_kfunc_call()` 仍无条件 clobber `r0-r5`，见 `vendor/linux-framework/kernel/bpf/verifier.c:14432-14437`
- 标量返回值仍然只做 `mark_reg_unknown(r0)`，见 `vendor/linux-framework/kernel/bpf/verifier.c:14453-14458`

### 1.2 当前 packed-encoding 提议的真实冲突

当前文档里把 `off` 当成 “通常为 0，可以拿来装操作数”，这对 module kfunc 不成立。

证据链：

- UAPI 约定：`BPF_CALL_KFUNC(OFF, IMM)` 的 `off` 就是 kfunc 的附加索引，见 `vendor/linux-framework/include/linux/filter.h:479-485`
- verifier 用 `off` 找 module BTF，见 `vendor/linux-framework/kernel/bpf/verifier.c:3415-3428` 和 `3469-3475`
- `bpf_kfunc_desc` 查找 key 是 `(func_id, offset)`，见 `vendor/linux-framework/kernel/bpf/verifier.c:3312-3323`
- JIT/后续 lookup 的 key 也是 `(imm, offset)`，见 `vendor/linux-framework/kernel/bpf/verifier.c:3693-3710`
- daemon 明确为每个 kfunc 打开 module BTF FD 并构造 `fd_array`，见 `daemon/README.md:178-190`、`daemon/src/pass.rs:376-391`

结论：对现有 BpfReJIT module kinsn，`off` 不是空闲字段。

### 1.3 当前 emit 契约也不是 “只写 r0”

`rotate` 的 x86 emit：

- `mov rcx, rsi`
- `rol rax, cl`

见 `module/x86/bpf_rotate.c:42-69`。

这会修改 x86 `RCX`，即 BPF `r4` 对应寄存器。也就是说：

- “Phase 0 直接改成只 clobber r0”会把当前 rotate kinsn 变成 verifier unsound
- per-kinsn clobber 是必需项，不是可选优化项

## 2. 设计目标

1. kinsn 在语义上是 kfunc 的子集，而不是一条全新 BPF ISA 指令。
2. 公开命名使用 `kinsn`，去掉旧命名。
3. verifier 不暴露 `struct bpf_reg_state` 给 module。
4. verifier 仍然是最终真相来源；module 只提供受限、可验证的 effect description。
5. 标准 kfunc ABI 必须继续工作，保证旧 daemon 可用。
6. packed operand ABI 如要引入，必须与 module BTF/`fd_array` 兼容。
7. memory kinsn 不能绕过现有内存安全检查。
8. API 需要支持未来 arm64/x86 的 emit 差异，但 verifier 模型应保持平台内聚。

## 3. 结构体与注册设计

### 3.1 推荐模式：独立 `bpf_kinsn_ops` sidecar

推荐模式：

- `btf_kfunc_id_set` 继续负责 “这个 kfunc 是否允许被某类 BPF prog 调用”
- `bpf_kinsn_ops` 负责 “如果它还是个 kinsn，那么 verifier 和 JIT 应如何理解它”
- 内部缓存点仍放在 `struct bpf_kfunc_desc` 上：
  - 当前字段 `inline_ops`
  - 改为 `const struct bpf_kinsn_ops *kinsn_ops`

### 3.2 为什么不是扩展 `btf_kfunc_id_set`

不推荐直接在 `btf_kfunc_id_set` 上扩字段：

- `btf_kfunc_id_set` 是 allowlist/flags 容器，不是行为对象
- 绝大多数 kfunc 不需要 JIT emit/verifier model，扩这个结构会污染所有 kfunc
- 它按 “一组 ID + flags” 注册，不适合放每个 kfunc 一份的行为指针
- 现有内核里类似对象通常是 “主体 + 单独 ops/desc sidecar”，不是往 ID set 里堆回调

### 3.3 为什么不是“包含一个 base kfunc 引用”

不推荐设计一个“`bpf_kinsn_ops` 里嵌一个 `struct bpf_kfunc *`”：

- 当前内核没有导出的 `struct bpf_kfunc`
- kfunc 的一等身份就是 `(btf, func_id, flags)`，不是一个可嵌入的对象
- 真正存在且稳定的缓存对象是内部 `struct bpf_kfunc_desc`

因此最自然的 IS-A 实现方式不是 C 结构体继承，而是：

- kinsn 必须先是一个合法 kfunc
- 然后可选地再绑定一份 `bpf_kinsn_ops`

### 3.4 与 kernel 既有模式的对应关系

这个选择符合现有 kernel 风格：

- `file_operations` / `net_device_ops`：行为通过独立 ops table 挂到主体对象上，不把行为塞进 ID set
- `bpf_struct_ops` + `bpf_struct_ops_desc`：主体行为对象和辅助描述信息分离，且带 `owner`、`verifier_ops`
- `bpf_prog_offload_ops`：module/subsystem 提供 verifier/JIT 相关回调，但通过受限 ops 接口，而不是暴露 verifier 内部实现

### 3.5 推荐公开定义

下面是推荐的公开定义。它把 verifier 和 JIT 两侧统一到一个对象里，但 verifier 看到的是 effect descriptor，而不是 `bpf_reg_state`。

```c
enum bpf_kinsn_encoding {
	BPF_KINSN_ENC_LEGACY_KFUNC = 1 << 0,
	BPF_KINSN_ENC_PACKED_CALL  = 1 << 1,
};

enum bpf_kinsn_result_type {
	BPF_KINSN_RES_VOID,
	BPF_KINSN_RES_SCALAR,
};

struct bpf_kinsn_scalar_state {
	struct tnum var_off;
	u64 umin_value;
	u64 umax_value;
	s64 smin_value;
	s64 smax_value;
	bool subreg32;
};

struct bpf_kinsn_operand {
	u8 kind;
	u8 regno;
	s16 imm16;
	s32 imm32;
};

struct bpf_kinsn_call {
	u8 encoding;
	u8 nr_operands;
	u8 dst_reg;
	u8 reserved;
	struct bpf_kinsn_operand operands[4];
	u64 payload;
};

struct bpf_kinsn_mem_access {
	u8 base_reg;
	u8 size;
	u8 access_type;
	u8 flags;
	s16 off;
};

struct bpf_kinsn_effect {
	u32 input_mask;
	u32 clobber_mask;
	enum bpf_kinsn_result_type result_type;
	u8 result_reg;
	u8 result_size;
	u8 nr_mem_accesses;
	u8 flags;
	struct tnum result_tnum;
	u64 umin_value;
	u64 umax_value;
	s64 smin_value;
	s64 smax_value;
	struct bpf_kinsn_mem_access mem_accesses[2];
};

struct bpf_kinsn_ops {
	struct module *owner;
	u16 api_version;
	u16 max_emit_bytes;
	u32 supported_encodings;

	int (*decode_call)(const struct bpf_insn *insn,
			   struct bpf_kinsn_call *call);
	int (*validate_call)(const struct bpf_kinsn_call *call,
			     struct bpf_verifier_log *log);
	int (*model_call)(const struct bpf_kinsn_call *call,
			  const struct bpf_kinsn_scalar_state *scalar_regs,
			  struct bpf_kinsn_effect *effect);

	int (*emit_x86)(u8 *image, u32 *off, bool emit,
			const struct bpf_kinsn_call *call,
			struct bpf_prog *prog);
	int (*emit_arm64)(u32 *image, int *idx, bool emit,
			  const struct bpf_kinsn_call *call,
			  struct bpf_prog *prog);
};
```

### 3.6 设计说明

1. `decode_call`

- 把 raw `bpf_insn` 解码成标准化 `bpf_kinsn_call`
- legacy kfunc ABI 下可以为 `NULL`，由 core 走默认解码
- packed ABI 下必须提供

2. `validate_call`

- 只验证编码语义
- 不接触 live verifier state
- 例如：width 是否在 1..64、select condition code 是否合法、packed payload 是否符合布局

3. `model_call`

- 这是核心 callback
- module 返回完整 effect：输入寄存器、clobber、结果类型/大小/range/tnum、内存访问描述
- 不再拆成 `clobber_mask` 和 `narrow_result()`

4. `emit_*`

- 和 verifier 共享同一个 `bpf_kinsn_call`
- 避免 verifier/JIT 各自重新解释 packed payload 而出现不一致

### 3.7 flag 命名

建议新增 `KF_KINSN`，语义上替代 `KF_INLINE_EMIT`。

- 对内核内部，所有 helper/变量名改成 `kinsn`
- 过渡期可以保留：

```c
#define KF_KINSN       (1 << N)
#define KF_INLINE_EMIT KF_KINSN
```

这样现有代码和文档能平滑迁移，但正式概念统一成 kinsn。

### 3.8 注册 API 设计

推荐保留 2 层 API：

低层：

```c
int bpf_register_kinsn_ops(const char *func_name,
			   const struct bpf_kinsn_ops *ops);
void bpf_unregister_kinsn_ops(const char *func_name);
```

实现约束：

- 公开 API 可以按 `func_name` 注册，便于 module 使用
- 但内核内部 registry 不应继续只用字符串做最终 key
- 正确做法是在注册时把它解析成 `(btf, func_id)` 后再入表
- 如果不同 BTF 中出现同名 kfunc，必须按 `(btf, func_id)` 区分，或在注册时直接拒绝歧义

高层：

- 模块仍然单独 `register_btf_kfunc_id_set(...)`
- `kinsn_common.h` 提供新的批量 helper，把 kfunc set 注册和 kinsn ops 注册打包

推荐的项目内 helper 形态：

```c
struct bpf_kinsn_desc {
	const char *func_name;
	const struct bpf_kinsn_ops *ops;
};

int bpf_register_kinsn_descs(const struct bpf_kinsn_desc *descs, u32 cnt);
void bpf_unregister_kinsn_descs(const struct bpf_kinsn_desc *descs, u32 cnt);
```

### 3.9 注册时必须做的校验

注册时建议强制检查：

1. `ops->owner != NULL`
2. 至少一个 `emit_*` 存在
3. `model_call != NULL`
4. packed ABI 时 `decode_call != NULL`
5. `KF_KINSN` 只能和受限 flag 组合
6. `supported_encodings` 只应声明“当前机器上可保证 inline 成功”的编码集合

建议直接禁止 `KF_KINSN` 与下列 flag 叠加：

- `KF_ACQUIRE`
- `KF_RELEASE`
- `KF_RET_NULL`
- `KF_ITER_NEW`
- `KF_ITER_NEXT`
- `KF_ITER_DESTROY`
- `KF_RCU`
- `KF_RCU_PROTECTED`
- `KF_SLEEPABLE`
- `KF_DESTRUCTIVE`
- `KF_FASTCALL`
- `KF_IMPLICIT_ARGS`
- `KF_ARENA_RET`
- `KF_ARENA_ARG1`
- `KF_ARENA_ARG2`

理由：这些 flag 都让 kfunc 带上“函数式/资源式/控制流式”语义，不像指令。

结论：`KF_KINSN` 最好只服务于“纯计算/纯 load/store-like”语义。

补充：

- 如果某个 encoding 只在部分 CPU feature 下可 inline，则模块不应无条件宣称支持它
- 更安全的做法是：
  - 仅注册可始终 inline 的通用实现
  - 或在注册时根据当前 CPU feature 缩减 `supported_encodings`

## 4. verifier 设计

### 4.1 总体原则

verifier 不直接信任 module 去改 `bpf_reg_state`。

推荐模型：

- module 只返回一个声明式 `bpf_kinsn_effect`
- core verifier 负责：
  - 检查输入寄存器是否已初始化
  - 检查寄存器类型是否符合约束
  - 检查内存访问是否合法
  - 应用 clobber
  - 应用结果范围、tnum、subreg_def

### 4.2 为什么不能暴露 `bpf_reg_state`

不推荐把 `struct bpf_reg_state *` 暴露给 module callback：

- 社区会首先质疑 verifier internal ABI 稳定性
- review 成本极高，任何 module 都可直接篡改完整 verifier 状态
- 内核版本演进时 `bpf_reg_state` 字段会频繁变化
- 安全上虽然 module 本来就是 trusted code，但维护性和可审计性会显著恶化

结论：暴露 `bpf_reg_state` 不安全，也不 upstream-friendly。

### 4.3 与已有先例的关系

module/subsystem 提供 verifier 侧 callback 并非没有先例：

- `struct bpf_prog_offload_ops` 有 `insn_hook/finalize/replace_insn/remove_insns`，见 `vendor/linux-framework/include/linux/bpf.h:1136-1148`
- `struct bpf_struct_ops` 带 `verifier_ops`，见 `vendor/linux-framework/include/linux/bpf.h:1966-2031`

但这些都是 subsystem-scoped callback，不是向任意 kfunc 暴露 raw verifier state。

结论：有先例支持“module 提供 verifier 协作”，但没有先例支持“module 任意写 `bpf_reg_state`”。因此必须收窄接口。

### 4.4 推荐 verifier 通用流程

伪代码如下：

```text
check_kfunc_call(env, insn, insn_idx_p):
    fetch meta
    desc = find_kfunc_desc(env->prog, insn->imm, insn->off)

    if !meta.has(KF_KINSN) or !desc->kinsn_ops:
        return check_plain_kfunc_call_existing_path(...)

    ops = desc->kinsn_ops

    call = core_decode_legacy_kfunc_call(insn)
    if ops->decode_call:
        err = ops->decode_call(insn, &call)
        if err:
            reject

    if !(ops->supported_encodings & BIT(call.encoding)):
        if call.encoding == BPF_KINSN_ENC_LEGACY_KFUNC:
            return check_plain_kfunc_call_existing_path(...)
        reject

    if ops->validate_call:
        err = ops->validate_call(&call, &env->log)
        if err:
            reject

    if call.encoding == BPF_KINSN_ENC_LEGACY_KFUNC:
        err = check_kfunc_args(env, &meta, insn_idx)
        if err:
            reject
    else:
        err = check_kinsn_encoded_operands(env, &call)
        if err:
            reject

    scalar_regs = collect_scalar_inputs(env, &call)

    err = ops->model_call(&call, scalar_regs, &effect)
    if err:
        reject

    err = core_validate_effect(&call, &effect)
    if err:
        reject

    err = core_check_mem_accesses(env, &effect)
    if err:
        reject

    core_apply_clobber_mask(env, regs, effect.clobber_mask, effect.result_reg)
    core_apply_result(env, regs, &effect)
    core_apply_subreg_def(env, regs, &effect)

    return 0
```

### 4.5 `core_validate_effect()` 应检查什么

至少检查：

1. `effect.input_mask` 只能引用有效 BPF regs
2. `effect.clobber_mask` 不能包含 `r10`/FP
3. `effect.result_reg` 必须属于 `clobber_mask`，除非 result 为 void
4. 非 void 结果只能是 scalar
5. `result_size` 只能是 `0/4/8`
6. pointer-base memory operand 不能同时被声明为 scratch clobber
7. packed ABI 下，所有寄存器引用必须由 `decode_call` 显式给出

### 4.6 为什么单独的 `clobber_mask` 字段不够

结论：静态 `u32 clobber_mask` 不够。

原因：

- legacy ABI 和 packed ABI 的结果寄存器不同
- in-place kinsn 的 clobber 可能取决于 `dst_reg`
- 某些实现只在特定编码下需要 scratch reg

因此推荐把 clobber 放进 `model_call()` 的返回结果里，做成 per-call。

### 4.7 `narrow_result()` 需要什么输入

`insn->off` 远远不够。

完整结果建模至少要看到：

1. 解码后的操作数
2. 所有输入标量寄存器的 range/tnum
3. 结果写到哪个寄存器
4. 对 memory kinsn，还要看到 core 已确认过的 memory access 语义

另外，当前 `check_kfunc_args()` 的 `meta->arg_constant` 只支持一个常量参数，见 `vendor/linux-framework/kernel/bpf/verifier.c:13496-13510` 与 `13867-13877`。这对 `extract(start, len)` 这种多常量场景本来就不够。

结论：不要做一个只看 `insn->off` 的 `narrow_result()`；直接做完整 `model_call()`。

### 4.8 input regs 是否需要单独 callback

概念上需要“声明哪些寄存器是输入”，但不建议单独再加一个 `input_regs()` callback。

推荐方式：

- `decode_call()` 解码出寄存器操作数
- `model_call()` 返回最终 `input_mask`

这样就够了。

### 4.9 tnum 是否需要

结论：完整方案里需要。

只设 min/max 不够：

- `select` 原始 BPF 语义本质上是两个值域的 union，tnum 能保留更多位级信息
- `extract` 原始 `rshift + and` 序列本来有较强的 tnum 传播
- `endian_load`、`rotate` 若完全丢掉 tnum，某些依赖位级精度的程序会退化

推荐：

- `bpf_kinsn_effect` 支持可选 `result_tnum`
- 没提供时，core 回落到 conservative unknown tnum

补充：

- `tnum` 已是公开 kernel 头的一部分，见 `vendor/linux-framework/include/linux/tnum.h`
- 这比暴露完整 `bpf_reg_state` 可接受得多

### 4.10 32-bit `subreg_def` 怎么处理

结论：必须由 core 统一处理，不能交给 module 直接写寄存器状态。

规则：

- `result_size == 8`：
  - `subreg_def = DEF_NOT_SUBREG`
- `result_size == 4`：
  - `subreg_def = env->insn_idx + 1`
- scratch-only clobber regs：
  - `mark_reg_not_init()`
  - `subreg_def = DEF_NOT_SUBREG`

这和现有 `__mark_btf_func_reg_size()` 的处理风格一致，见 `vendor/linux-framework/kernel/bpf/verifier.c:12266-12288`。

### 4.11 subprog 场景

结论：kinsn 应允许出现在普通 subprog 中，不需要额外禁止。

理由：

- kfunc 已在 `add_subprog_and_kfunc()` 里统一处理，见 `vendor/linux-framework/kernel/bpf/verifier.c:3728-3755`
- 当前 verifier 只对极少数特殊 kfunc 在 callback subprog 做限制，例如 `bpf_throw`，见 `vendor/linux-framework/kernel/bpf/verifier.c:6917-6919`

因此：

- 普通 subprog：允许
- callback subprog：沿用现有 kfunc 的特殊限制；kinsn 框架本身不新增全局禁止

### 4.12 memory kinsn 需要什么额外验证

结论：必须有，而且不能只靠 module callback。

至少需要：

1. memory access validity

- base reg 类型
- offset
- size
- read/write 权限
- packet/map/stack/btf ptr 边界

2. 对 load-like kinsn，还需要结果建模

- 最好复用现有 load path 的结果建模，尤其是 stack spill/const stack 场景
- 不能简单地只设 “0..255” 之类的宽范围，否则会比原始 `LDX + ENDIAN` 更弱

推荐设计：

- `model_call()` 只声明 memory access intent
- core verifier 新增内部 helper：
  - `bpf_kinsn_check_mem_access()`
  - `bpf_kinsn_build_scalar_load_state()`
- 对 `endian_load` 这类 fused load，core 先构造 “原始 load 的 scalar state”，再由 `model_call()` 做 byte-swap 变换

这是 memory kinsn 和纯 ALU kinsn 的最大差异。

## 5. operand encoding 设计结论

### 5.1 不推荐 `dst_reg + off` 直接编码

明确结论：

- `dst_reg` 可用，但 `off` 不可作为 module kinsn 的主承载字段
- 因而 “`dst_reg` 编寄存器、`off` 编常量”不能作为当前推荐主方案

### 5.2 `check_kfunc_args()` 怎么适配

推荐答案：

- legacy ABI：继续走现有 `check_kfunc_args()`
- packed ABI：不再复用 `check_kfunc_args()`，而是走新的 `check_kinsn_encoded_operands()`

理由：

- `check_kfunc_args()` 是围绕 `r1-rN` BTF 参数设计的
- packed ABI 的输入来源不一定是 `r1-rN`
- 强行适配会让 kfunc 路径更混乱

### 5.3 多操作数 `select` 怎么编码

如果未来要做 packed ABI，推荐使用 sidecar payload，而不是占用 `off`。

推荐形态：

- 紧邻 kfunc call 之前放一个 metadata pseudo-insn
- payload 里编码：
  - result reg
  - cond reg
  - true src reg
  - false src reg
  - cond code
  - 可选 imm

典型布局可以是一个 64-bit payload：

- 4 bits x 4 个 reg slot
- 4 bits condition
- 剩余位放 immediate / flags

### 5.4 为什么 sidecar payload 比 `off` 更合理

优点：

1. 不破坏 module BTF `fd_array` 解析
2. 可以承载多个寄存器和常量
3. verifier/JIT 可以共享同一个 decode 结果
4. 旧 daemon 完全不受影响

代价：

- 新增一个 pseudo-insn/sidecar 约定
- verifier 和 disasm 需要认识这个 pair

### 5.5 向后兼容结论

旧 daemon 生成的标准 kfunc call 必须继续工作。

推荐兼容策略：

1. 旧 daemon

- 继续发标准 kfunc ABI
- 如果 `kinsn_ops` 根本不存在，或存在但不声明 `BPF_KINSN_ENC_LEGACY_KFUNC`，则保持 plain kfunc 路径
- 若验证时没有选中 kinsn path（例如没有 `desc->kinsn_ops`），则仍按 plain kfunc 语义工作
- 若验证时选中了 kinsn path，则按 `model_call()` 建模
- 一旦按 kinsn 语义建模，JIT 就必须 inline；不能在编译末端再偷偷退回普通 kfunc call

2. 新 daemon packed ABI

- 只有当 kernel 宣告支持 packed ABI 且对应 `kinsn_ops->supported_encodings` 包含它时才启用
- 不满足时，daemon 回落到 legacy kfunc ABI

3. 所有已选中的 kinsn path 都不能依赖“emit 失败后 fallback 普通 call”

- packed ABI 没有标准 `r1-rN` 实参布局
- legacy ABI 即使有标准参数布局，只要 verifier 已按精确 clobber/result 建模，再退回 plain call 也会破坏合同

结论：

- “plain kfunc call” 和 “kinsn path” 是验证阶段就要选定的两条不同语义路径
- 只有在验证阶段没有进入 kinsn path 时，JIT 才能生成普通 kfunc call
- 一旦进入 kinsn path，emit 失败应当是硬失败，而不是 fallback

## 6. 对用户问题的逐项回答

### 6.1 结构体设计

结论：

- 不扩 `btf_kfunc_id_set`
- 定义独立的 `struct bpf_kinsn_ops`
- 内部在 `struct bpf_kfunc_desc` 上缓存 `kinsn_ops`
- 通过注册 API 把 kinsn ops 和 kfunc 关联

这是最符合内核惯例的方案。

### 6.2 verifier callback 完整性

#### a. `clobber_mask` 错误声明的后果

如果声明偏大：

- 只是更保守
- 可能损失一些优化和 acceptance rate

如果声明偏小：

- verifier 可能错误保留 live reg
- runtime 语义会错
- 如果被保留的是指针/边界相关寄存器，还可能把 verifier soundness 一起打穿

它和 emit callback 的信任模型是同一级别问题：

- emit callback 错了，本来就能生成错误甚至危险的 native code
- model callback 错了，则 verifier/JIT 合同不一致

结论：`clobber_mask` 错误声明不是“新的不可信输入”，但确实是同等级的 trusted-kernel-code bug。

#### b. `narrow_result()` 只看 `insn->off` 够不够

不够。

至少还需要：

- 解码后的所有操作数
- 输入标量寄存器的 range/tnum
- 结果寄存器位置
- 对 memory kinsn，还需要 load/memory access 上下文

#### c. 是否还需要 `verify_operands`

需要，但应叫 `validate_call()`，并且只看编码，不看 live verifier state。

#### d. 是否需要 `input_regs`

概念上需要；实现上不需要单独 callback。

- `decode_call()` + `model_call().input_mask` 就足够

#### e. tnum 追踪要不要

完整方案里要。

#### f. 32-bit `subreg_def`

由 core 根据 `result_size` 统一设置。

#### g. subprog 场景

允许，沿用现有 kfunc 规则。

#### h. memory kinsn 额外验证

必须要，而且 core 需要负责，不应下放给 module。

### 6.3 operand encoding

#### a. `check_kfunc_args()` 如何适配

legacy ABI 走现有路径；packed ABI 走新的 kinsn operand checker。

#### b. 多操作数如何编码

不要复用 `off`；用 sidecar payload。

#### c. 向后兼容

旧 daemon 标准 kfunc call 全部保留。

### 6.4 上游可接受性

#### a. module 提供 verifier callback 的顾虑

社区主要会担心：

1. verifier internal ABI 污染
2. soundness review 成本
3. out-of-tree module 滥用
4. per-kfunc callback 爆炸

缓解方式：

- 不暴露 `bpf_reg_state`
- callback 只返回声明式 effect
- 限定 `KF_KINSN` 可叠加的 flag
- 只允许 scalar/void result
- memory check 仍由 core 执行

#### b. 暴露 `bpf_reg_state` 给 module 安全吗

不安全，也不应该这么做。

#### c. 类似先例

有弱先例：

- `bpf_prog_offload_ops`
- `bpf_struct_ops.verifier_ops`
- 各 prog type 的 `bpf_verifier_ops`

没有强先例的是“export 一个通用 per-kfunc raw reg-state callback 给 module”。

#### d. 与 `bpf_fastcall` 的关系

结论：两者是邻近概念，但不应叠加。

`bpf_fastcall` 的本质：

- 编译器先 spill/fill
- verifier/JIT 再识别 pattern 并删掉多余 spill/fill

`kinsn_ops` 的本质：

- verifier 直接知道真实 clobber 和结果语义
- 不依赖编译器生成的 pattern

另外 `bpf_fastcall` 的 clobber 模型来自 BTF 参数个数，见 `vendor/linux-framework/kernel/bpf/verifier.c:18471-18630`，这和 packed ABI 明显不匹配。

推荐：

- `KF_KINSN` 与 `KF_FASTCALL` 互斥

## 7. 还缺什么 / 边界条件 / 安全点

### 7.1 当前 `endian_load(u64 addr)` 原型本身不可 upstream

这是当前设计里最大的安全问题之一。

现在 `module/x86/bpf_endian.c` 的 fallback 原型是：

- `u64 bpf_endian_loadXX(u64 addr)`

verifier 只会把它当普通 scalar 参数检查，不会验证地址是否合法。但 fallback 实现会直接解引用这个地址。

结论：对任意可调用该 kfunc 的程序，这个接口本身是不安全的。

修正建议：

- legacy ABI 下改成 typed pointer 原型，而不是 `u64 addr`
- 例如 `const void *addr`
- 如需常量偏移，走普通 add+call 或 packed ABI sidecar

### 7.2 verifier/JIT decode 必须共享

如果 packed ABI 的 decode 在 verifier 和 JIT 各写一份，后续极易漂移。

推荐：

- verifier decode 完把 `bpf_kinsn_call` 缓存在 `insn_aux_data`
- JIT 直接消费同一份 decode 结果

### 7.3 disasm / verifier log 需要认识 kinsn

当前 disasm 对 kfunc 只打印名字，见 `vendor/linux-framework/kernel/bpf/disasm.c:35-39` 与 `vendor/linux-framework/kernel/bpf/verifier.c:4275-4289`。

如果引入 packed ABI，日志必须能打印出已解码操作数，否则调试几乎不可用。

### 7.4 `rotate` 的 tnum helper 可能需要补

`extract`、`select`、`bswap` 都相对容易做 tnum 建模。

但 `rotate` 若想达到接近原始 BPF 序列的精度，可能需要新增内部 `tnum_rol64()` helper；否则 v1 可以接受 conservative unknown。

### 7.5 kinsn 应限制为“无资源语义”

不要让 kinsn 背 refcount、iterator、sleepable、throw、callback 注册之类语义。

否则 verifier 特例会指数级膨胀。

### 7.6 arch-specific clobber 要明确

clobber 是对 BPF 可见寄存器的承诺，不是“emit 看着办”。

例如：

- x86 rotate 需要 `r4` scratch
- arm64 版本未必同样需要

这没有问题，因为 ops 本身就是按当前架构注册的；但文档和自测必须写清楚。

### 7.7 selftest 必须覆盖“model/emit 一致性”

至少需要：

1. 每个 kinsn 的 clobber selftest
2. verifier modeled result range selftest
3. legacy ABI 和 packed ABI 的等价性 selftest
4. memory kinsn 的 invalid access reject selftest

## 8. 推荐实施顺序

### Phase A: rename + sidecar ops

- `bpf_kfunc_inline_ops` -> `bpf_kinsn_ops`
- `inline_ops` -> `kinsn_ops`
- `KF_INLINE_EMIT` -> `KF_KINSN` alias

### Phase B: verifier effect model

- 引入 `model_call()`
- 支持 per-call clobber 和 result range/tnum
- 先只做 legacy ABI

### Phase C: memory kinsn core helper

- 引入 memory access descriptor
- 引入 load-like kinsn 的 scalar-state builder

### Phase D: optional packed ABI

- 引入 sidecar payload
- 新 daemon 在 capability 检查后启用

## 9. 估计改动量

### 9.1 核心内核改动量

不含各具体 kinsn module 的算法改写，只算框架层：

1. `include/linux/bpf.h`

- `bpf_kinsn_ops` 和相关辅助结构/原型
- 预计 `+90 ~ +130 LOC`

2. `include/linux/btf.h`

- `KF_KINSN` flag alias/注释
- 预计 `+5 ~ +12 LOC`

3. `kernel/bpf/verifier.c`

- registry rename
- `bpf_kfunc_desc` 改字段
- `check_kinsn_call` 新路径
- effect 验证与应用
- memory kinsn helper
- disasm/log support glue
- 预计 `+260 ~ +360 LOC`

4. `arch/x86/net/bpf_jit_comp.c`

- JIT emit helper -> `emit_kinsn_call`
- 消费标准化 `bpf_kinsn_call`
- kinsn path must-inline 规则
- 预计 `+40 ~ +70 LOC`

5. `module/include/kinsn_common.h`

- 注册宏改名并换新 API
- 预计 `+40 ~ +80 LOC`

### 9.2 packed ABI 额外改动

如果继续推进 packed ABI sidecar：

- UAPI pseudo 定义
- verifier sidecar 解析
- disasm/log 支持
- JIT 读取 sidecar payload

预计额外：

- `+120 ~ +180 LOC`

### 9.3 总结

推荐主线（不含 packed ABI）：

- kernel core + project module header 合计约 `435 ~ 652 LOC`

加上 packed ABI：

- 合计约 `555 ~ 832 LOC`

这个量级明显高于“只改 10 行 verifier”，但这是完整、可 upstream 也可自洽的方案；同时远低于“新增一类 BPF 指令”所需改动。

## 10. 最终推荐

最终推荐如下：

1. 把 kinsn 正式定义为 `bpf_kinsn_ops`，不再沿用旧命名。
2. 采用独立 sidecar registry，而不是扩 `btf_kfunc_id_set`。
3. verifier 侧不要做 “只 clobber r0” 特判；必须做 per-call effect model。
4. 不暴露 `bpf_reg_state` 给 module；module 只返回声明式 `bpf_kinsn_effect`。
5. `clobber_mask + narrow_result()` 不够，统一为 `model_call()`。
6. memory kinsn 必须走 core memory validation，且最好复用 load result 建模。
7. `off` 不能作为 module kinsn 的主操作数字段；packed ABI 要单独设计 sidecar。
8. `KF_KINSN` 与 `KF_FASTCALL` 互斥。
9. 旧 daemon 的标准 kfunc call 必须保持可用；packed ABI 作为后续可选增强。

这套方案能同时解决：

- 当前 verifier 无条件 clobber 导致的 780+ skip
- 现有 `rotate` 等 kinsn 的真实 scratch/clobber 建模
- verifier precision 不足
- memory kinsn 的安全漏洞
- 后续 packed ABI 的扩展空间

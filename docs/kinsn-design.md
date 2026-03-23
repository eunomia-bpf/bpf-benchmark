# kinsn 核心设计

本文是 BpfReJIT 中 `kinsn` 抽象的长期维护文档，面向 reviewer、维护者和后续贡献者。它描述当前代码中的真实机制，而不是一次性的设计报告。

文中以当前实现为准，尤其以这些文件为准：

- `vendor/linux-framework/include/linux/bpf.h`
- `vendor/linux-framework/kernel/bpf/verifier.c`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
- `vendor/linux-framework/include/uapi/linux/bpf.h`
- `module/include/kinsn_common.h`
- `module/x86/bpf_rotate.c`
- `module/x86/bpf_extract.c`
- `module/x86/bpf_select.c`
- `module/x86/bpf_endian.c`
- `module/x86/bpf_barrier.c`
- `daemon/src/passes/*.rs`
- `tests/unittest/rejit_kinsn_packed.c`

设计演进背景可参考：

- `docs/kernel-jit-optimization-plan.md` §4.4
- `docs/tmp/20260323/kinsn_ops_design_20260323.md`
- `docs/tmp/20260323/kinsn_register_design_20260323.md`

## 1. 概述

### 1.1 kinsn 是什么

`kinsn` 是 BpfReJIT 引入的平台特定指令扩展机制。它不是一条新的 BPF ISA opcode；它首先是一个合法 `kfunc`，再额外挂上一份 `struct bpf_kinsn_ops` sidecar，用来定义：

- verifier 应该如何理解这次调用
- JIT 应该如何把它展开成目标架构的 native 指令序列

这使得 `kinsn` 在系统里保持了 “IS-A kfunc” 的身份：

- 可见性和 allowlist 仍由 BTF kfunc 机制管理
- 生命周期仍由 module + kfunc 基础设施管理
- 编码仍然是 “kfunc CALL”，不是新指令类

### 1.2 为什么需要 kinsn

BpfReJIT 的高层思路是：

- userspace daemon 负责发现热点模式、做策略决策、重写 BPF 字节码
- kernel 负责重新验证和重新 JIT

其中，daemon 只能做 “把某段 BPF 模式替换成另一个更短/更适合目标架构的表示”；它不能直接告诉 verifier “请相信我这段 native 代码是安全的”。

`kinsn` 的作用，就是给这种替换提供一个内核认可的、可验证的目标抽象：

- daemon 把模式替换成一个 `kinsn` 调用
- verifier 按该 `kinsn` 的声明式 effect 建模
- JIT 按该 `kinsn` 的 emit 回调发射 native 指令

这样，BpfReJIT 可以在不把优化策略写进 verifier 的前提下，引入平台特定指令。

### 1.3 kinsn 在 BpfReJIT 架构中的角色

在三组件架构里，`kinsn` 是最小内核机制层：

- daemon：决定“哪里替换、替换成什么”，这是 policy
- `kinsn` core：决定“这种替换如何编码、如何验证、如何发射”，这是 mechanism
- JIT：消费标准化后的 `bpf_kinsn_call`，发射架构相关代码

因此，`kinsn` 的定位不是“一个优化 pass”，而是“让优化 pass 可被 verifier 接受、可被 JIT 展开的通用承载层”。

## 2. 设计原则

### 2.1 微内核分离：mechanism vs policy

`kinsn` 机制刻意把“能做什么”和“何时去做”分开：

- kernel 只提供最小机制：注册、解码、验证 effect、JIT emit
- daemon 负责策略：模式匹配、收益评估、站点选择、是否应用

kernel 不知道 “rotate dense benchmark 里哪里值得替换”，也不应该知道；它只知道 “如果你给我一个 `bpf_rotate64` kinsn，我会如何验证和发射它”。

### 2.2 声明式 effect，而不是开放式 verifier hook

`bpf_kinsn_ops::model_call()` 不直接拿到 `struct bpf_reg_state *`，而是只接收：

- 标准化的 `struct bpf_kinsn_call`
- 每个标量输入操作数的只读摘要 `struct bpf_kinsn_scalar_state`

它输出的是声明式 `struct bpf_kinsn_effect`：

- 哪些寄存器是输入
- 哪些寄存器会被 clobber
- 结果寄存器是谁
- 结果的位宽、区间、tnum 是什么
- 是否存在内存访问，以及访问语义是什么

最终真正修改 verifier 状态的逻辑仍在 core：

- `bpf_validate_kinsn_effect()`
- `bpf_kinsn_check_mem_accesses()`
- `bpf_kinsn_apply_clobber_mask()`
- `bpf_kinsn_apply_result()`
- `bpf_kinsn_apply_subreg_def()`

这保证了 module 不会通过私有 callback 直接篡改 verifier 内部状态。

### 2.3 零 verifier 特例

新增一个 kinsn，不应该要求：

- 在 verifier 里加一个新的 `switch (func_name)`
- 在 backtracking 里写新的特判
- 在 memory checker 里手写一条新的旁路规则

当前实现的目标正是如此：

- verifier 只有一条通用 `check_kinsn_call()` 路径
- 每个具体 kinsn 的差异都封装在 `decode_call` / `validate_call` / `model_call`
- backtracking 只依赖 `insn_aux_data.kinsn_clobber_mask`

这意味着“新增 kinsn = 新 module +（通常）新 daemon pass”，而不是“新 module + verifier 补丁”。

## 3. Packed ABI 编码格式

### 3.1 为什么是 sidecar pseudo-insn，而不是复用 `CALL.off`

当前 packed ABI 不是把操作数塞进 `CALL.off`，而是使用一条紧邻 `CALL` 之前的 sidecar pseudo-insn：

```c
#define BPF_PSEUDO_KINSN_SIDECAR 3
```

这样设计的关键原因是：`CALL.off` 仍然要保留给 module kfunc 的 BTF FD slot。

对 module kfunc 而言：

- `CALL.imm = kfunc` 的 BTF ID
- `CALL.off = fd_array` 中 module BTF FD 的 1-based slot

daemon 侧的 `ensure_module_fd_slot()` 和 `call_kfunc_with_off()` 正是在维护这件事。也就是说，packed ABI 必须与 module kfunc 的 `fd_array` 兼容，不能抢占 `CALL.off`。

### 3.2 标准 BPF 指令格式对比

标准 BPF 指令是 64-bit：

| 字段 | 位数 | 说明 |
| --- | ---: | --- |
| `code` | 8 | opcode |
| `dst_reg` | 4 | 目的寄存器 |
| `src_reg` | 4 | 源寄存器 / pseudo tag |
| `off` | 16 | 偏移 / 辅助字段 |
| `imm` | 32 | 立即数 |

packed kinsn 使用两条指令组成一个逻辑调用：

| 载体 | 固定字段 | 可变字段 | 用途 |
| --- | --- | --- | --- |
| sidecar | `code = BPF_ALU64 | BPF_MOV | BPF_K`，`src_reg = BPF_PSEUDO_KINSN_SIDECAR` | `dst_reg` + `off` + `imm` | 承载 52-bit payload |
| call | `code = BPF_JMP | BPF_CALL`，`src_reg = BPF_PSEUDO_KFUNC_CALL` | `off = fd_slot`，`imm = btf_id` | 指向目标 kfunc |

因此：

- sidecar 的 `code` 和 `src_reg` 只是 tag
- sidecar 的 `dst_reg/off/imm` 被重新解释为 payload
- 紧随其后的 `CALL` 仍然保持标准 kfunc 语义

### 3.3 52-bit payload 的位布局

kernel 中 `bpf_kinsn_sidecar_payload()` 的定义是：

```c
static inline u64 bpf_kinsn_sidecar_payload(const struct bpf_insn *insn)
{
	return (u64)insn->dst_reg |
	       ((u64)(u16)insn->off << 4) |
	       ((u64)(u32)insn->imm << 20);
}
```

因此 payload 位布局如下：

| payload bits | 来自 sidecar 字段 | 宽度 | 说明 |
| --- | --- | ---: | --- |
| `[3:0]` | `dst_reg` | 4 | payload 低 4 bit |
| `[19:4]` | `off` | 16 | payload 中间 16 bit |
| `[51:20]` | `imm` | 32 | payload 高 32 bit |

注意：

- 这是“按位搬运”，不是按 signed 语义解释
- `off` 和 `imm` 虽然在 C 结构里分别是 `s16` / `s32`，但这里通过 `(u16)` / `(u32)` 提取 raw bits
- 可用 payload 一共是 `4 + 16 + 32 = 52` bit

daemon 和 selftest 都按同一规则构造 sidecar：

```c
#define BPF_KINSN_SIDECAR(PAYLOAD) \
	BPF_RAW_INSN(BPF_ALU64 | BPF_MOV | BPF_K, \
		     (__u8)((__u64)(PAYLOAD) & 0xf), \
		     BPF_PSEUDO_KINSN_SIDECAR, \
		     (__s16)(((__u64)(PAYLOAD) >> 4) & 0xffff), \
		     (__s32)(((__u64)(PAYLOAD) >> 20) & 0xffffffffU))
```

### 3.4 Packed 调用对 verifier/JIT 的可见形态

逻辑上，一个 packed kinsn call 长这样：

```text
[sidecar MOV.K pseudo] [CALL kfunc]
```

例如 rotate：

```text
sidecar.payload = dst | (src << 4) | (shift << 8)
call.imm        = bpf_rotate64 的 btf_id
call.off        = module fd 在 fd_array 中的 slot
```

verifier 和 JIT 都会把这对指令标准化成同一个 `struct bpf_kinsn_call`：

```c
struct bpf_kinsn_call {
	u8 encoding;
	u8 nr_operands;
	u8 dst_reg;
	u8 reserved;
	struct bpf_kinsn_operand operands[4];
	u64 payload;
};
```

其中：

- `encoding` 表示 `LEGACY_KFUNC` 还是 `PACKED_CALL`
- `dst_reg` 是 packed 结果寄存器
- `operands[]` 是解码后的寄存器/立即数操作数
- `reserved` 允许某些 kinsn 携带额外 nibble 级别的元信息
- `payload` 保留原始 52-bit 值，便于 module 自己再解释

### 3.5 每个现有 kinsn 的 payload 布局

| kinsn | payload 布局 | 当前用途 |
| --- | --- | --- |
| `bpf_rotate64` | `dst[3:0] \| src[7:4] \| shift[15:8]` | 原地/拷贝后 `ROL imm8` |
| `bpf_extract64` | `dst[3:0] \| start[15:8] \| len[23:16]` | 对 `dst` 做 `shr + and` |
| `bpf_select64` | `dst[3:0] \| true[7:4] \| false[11:8] \| cond[15:12] \| cc[19:16]` | 当前 `cc=0` 表示 `cond != 0` |
| `bpf_endian_load16/32/64` | `dst[3:0] \| base[7:4]` | 从 `base` 指向地址读并做 byte swap |
| `bpf_speculation_barrier` | `0` | payload 必须全零 |

当前实现里，payload 只使用了低位一小段。52-bit 空间保留了后续扩展余量，但是否扩展，必须继续遵守 “不抢 `CALL.off`、不新增 verifier 特例” 这两个约束。

### 3.6 与当前 daemon emission 的对应关系

当前 daemon 统一使用：

```rust
pub fn emit_packed_kfunc_call_with_off(
    payload: u64,
    kfunc_btf_id: i32,
    kfunc_off: i16,
) -> Vec<BpfInsn> {
    vec![
        BpfInsn::kinsn_sidecar(payload),
        BpfInsn::call_kfunc_with_off(kfunc_btf_id, kfunc_off),
    ]
}
```

这意味着所有 packed kinsn 在字节码层面都共享同一个 ABI 骨架，差别只在 payload 编码和目标 `btf_id`。

## 4. 完整数据流

本节按 “daemon emit -> verifier decode/validate/model/apply -> JIT decode/emit” 的顺序展开。

### 4.1 daemon：发现能力并决定是否能发 packed

能力发现发生在 `daemon/src/kfunc_discovery.rs`：

1. 扫描已加载 module 的 BTF，找到 kfunc 名称对应的 `btf_id`
2. 记录 module 的 BTF FD
3. 把该 kfunc 标记为支持 `BPF_KINSN_ENC_PACKED_CALL`

落到 `KfuncRegistry` 里之后，pass 侧会通过这些接口做 gating：

- `packed_supported_for_pass()`
- `packed_supported_for_kfunc_name()`
- `module_fd_for_pass()`

当前 daemon 的 kinsn passes 不再回退到 legacy 发射路径；如果 packed 不可用，pass 会选择 skip，而不是生成旧 ABI。

### 4.2 daemon：构造 payload 并发 sidecar + CALL

以 rotate 为例，`daemon/src/passes/rotate.rs` 会：

1. 通过 `module_fd_for_pass("rotate")` 找到 module FD
2. 用 `ensure_module_fd_slot()` 确保该 FD 出现在 REJIT `fd_array` 中
3. 按 `dst | (src << 4) | (shift << 8)` 构造 payload
4. 调用 `emit_packed_kfunc_call_with_off(payload, btf_id, kfunc_off)`

其他 pass 也遵循同一模式：

- `extract.rs`：构造 `dst | (start << 8) | (len << 16)`
- `cond_select.rs`：构造 `dst | (a << 4) | (b << 8) | (cond << 12)`
- `endian.rs`：构造 `dst | (base << 4)`，必要时先 materialize offset
- `spectre.rs`：构造零 payload 的 barrier 调用

### 4.3 verifier：在 kfunc desc 上绑定 kinsn_ops

程序 load / specialize kfunc 时，verifier 会为每个 kfunc 调用缓存一份 `struct bpf_kfunc_desc`。在这一步：

```c
desc->kinsn_ops = kfunc.flags && (*kfunc.flags & KF_KINSN) ?
		  bpf_kinsn_lookup(kfunc.name) : NULL;
```

也就是说，只有同时满足这两个条件才会进入 kinsn 路径：

- 目标 kfunc 带 `KF_KINSN`
- 内核里已经为该名字注册了 `bpf_kinsn_ops`

如果 target 不是注册过的 kinsn，但程序里却放了 sidecar，verifier 会直接拒绝。

### 4.4 verifier：找到 sidecar 并标准化成 `bpf_kinsn_call`

真正检查某条 `CALL` 指令时，入口还是 `check_kfunc_call()`。它在看到 `KF_KINSN` 后转入 `check_kinsn_call()`。

核心流程如下：

1. `bpf_verifier_find_kinsn_sidecar(env, insn_idx)`
   - 只接受“紧邻前一条”的 sidecar
   - 不能跨 subprog 边界
2. `bpf_prepare_kinsn_call(insn, sidecar, nargs, ops, &call)`
   - 无 sidecar 时先走 `bpf_build_legacy_kinsn_call()`
   - 有 sidecar 时先把 `encoding` 设成 `BPF_KINSN_ENC_PACKED_CALL`
   - 再统一调用 `ops->decode_call()`

这一步非常关键：verifier 和 JIT 共用 `bpf_prepare_kinsn_call()`，所以不会出现 “verifier 一种解码方式、JIT 另一种解码方式”。

### 4.5 verifier：validate / operand check / scalar input 收集

得到 `call` 后，`check_kinsn_call()` 依次执行：

1. `ops->validate_call(&call, &env->log)`
   - 检查 payload 是否符合该 kinsn 的局部规则
2. 若 `call.encoding == LEGACY_KFUNC`
   - 调用现有 `check_kfunc_args()`
3. 若 `call.encoding == PACKED_CALL`
   - 调用 `check_kinsn_encoded_operands()`
   - 要求所有寄存器操作数都显式出现在 `call.operands[]`
4. `bpf_collect_kinsn_scalar_inputs()`
   - 从当前 verifier 寄存器状态里提取标量摘要
   - 形成 `struct bpf_kinsn_scalar_state scalar_regs[4]`

这里有一个重要区别：

- legacy ABI 的输入来源默认是 `r1-rN`
- packed ABI 的输入来源完全由 `decode_call()` 给出的 `operands[]` 决定

### 4.6 verifier：调用 `model_call()`，拿到声明式 effect

然后 verifier 执行：

```c
bpf_kinsn_init_effect(&effect);
err = ops->model_call(&call, scalar_regs, &effect);
```

module 在这里不能直接操作 verifier state，只能填 `effect`。例如：

- rotate：声明 “输入是 src，clobber/result 是 dst”
- extract：再额外声明 “结果范围是 `[0, 2^len-1]`”
- endian：再声明 “有一个 memory read，且该读结果就是返回值”

### 4.7 verifier：core 验证 effect 并应用

拿到 effect 后，core 会依次执行：

1. `bpf_validate_kinsn_effect()`
2. `bpf_kinsn_check_input_regs()`
3. `bpf_kinsn_check_mem_accesses()`
4. `bpf_kinsn_apply_clobber_mask()`
5. `bpf_kinsn_apply_result()`
6. `bpf_kinsn_apply_subreg_def()`

同时还会把这两个信息写进 `insn_aux_data`：

- `kinsn_call = true`
- `kinsn_clobber_mask = effect.clobber_mask`

这样 backtracking 阶段就能知道：

- 这不是普通 helper/kfunc call
- 哪些寄存器真的会被这个 kinsn call 点 clobber

### 4.8 verifier：memory kinsn 的特殊点仍在 core，而不在 module

如果 effect 声明了 `mem_accesses[]`，verifier 会继续走现有 memory safety 逻辑：

- `check_mem_access()` 验证 base pointer、offset、size、访问类型
- 如果访问带 `BPF_KINSN_MEM_RESULT`，则复制 load state 到结果寄存器
- 之后再把 `result_tnum` / `umin` / `umax` 等范围信息与它求交

这正是“声明式 effect + core apply”的价值：module 说的是“我要读哪里、结果是什么”，真正判断“这次读是否合法”的仍是 verifier core。

### 4.9 JIT：重新解码并发射 native 指令

到 JIT 阶段，x86 在 `arch/x86/net/bpf_jit_comp.c` 的 `BPF_CALL` case 中判断：

```c
if (src_reg == BPF_PSEUDO_KFUNC_CALL &&
    bpf_jit_find_kinsn_ops(bpf_prog, insn)) {
	err = emit_kinsn_call(&prog, bpf_prog, insn, !!rw_image);
	...
}
```

`emit_kinsn_call()` 的流程是：

1. `bpf_jit_find_kinsn_ops()` 找到 `desc->kinsn_ops`
2. `bpf_jit_get_kinsn_call()` 再次调用 `bpf_prepare_kinsn_call()`
3. `ops->emit_x86(prog, &off, emit, &call, bpf_prog)`
4. 检查：
   - 返回值必须等于实际写入字节数
   - 不能超过 `ops->max_emit_bytes`

这条路径说明了两个设计点：

- verifier 和 JIT 消费同一个标准化 `bpf_kinsn_call`
- 一旦 verifier 选择了 kinsn 语义，JIT 就必须 inline；emit 失败是硬失败，不允许悄悄退回普通 kfunc call

## 5. `bpf_kinsn_ops` API

### 5.1 结构体

当前公开定义如下：

```c
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

### 5.2 字段语义

| 字段 | 语义 | 当前约束 |
| --- | --- | --- |
| `owner` | 所属 module | 注册时必须非空 |
| `api_version` | API 版本号 | 当前模块都填 `1` |
| `max_emit_bytes` | 单次 emit 最大字节数/word 数上界 | 注册时必须大于 0，JIT 会强校验 |
| `supported_encodings` | 支持的编码位图 | 至少包含一种编码；legacy 不支持时 verifier 会回退普通 kfunc 路径，packed 不支持时会拒绝 |

### 5.3 每个 callback 的签名、语义、调用时机

| callback | 签名 | 调用时机 | 语义 |
| --- | --- | --- | --- |
| `decode_call` | `int (*)(const struct bpf_insn *insn, struct bpf_kinsn_call *call)` | verifier/JIT 都会调用 | 把 raw BPF 指令对解码成规范化 `bpf_kinsn_call`；packed 编码必须提供 |
| `validate_call` | `int (*)(const struct bpf_kinsn_call *call, struct bpf_verifier_log *log)` | verifier decode 之后 | 做 kinsn 私有语法校验，例如立即数范围、保留位必须为 0 |
| `model_call` | `int (*)(const struct bpf_kinsn_call *call, const struct bpf_kinsn_scalar_state *scalar_regs, struct bpf_kinsn_effect *effect)` | verifier operand check 之后 | 返回声明式 effect，不能直接改 verifier state；`scalar_regs[i]` 只对被识别为 scalar 的寄存器操作数有意义 |
| `emit_x86` | `int (*)(u8 *image, u32 *off, bool emit, const struct bpf_kinsn_call *call, struct bpf_prog *prog)` | x86 JIT | 按 `call` 发射 native 字节，返回写入长度 |
| `emit_arm64` | `int (*)(u32 *image, int *idx, bool emit, const struct bpf_kinsn_call *call, struct bpf_prog *prog)` | arm64 JIT | 与 `emit_x86` 同义，但目标是 arm64 |

### 5.4 `decode_call()` 的约定

`decode_call()` 必须把 raw encoding 归一化为 `bpf_kinsn_call`，当前有几个重要约束：

- packed ABI 下，必须显式填出所有会被 effect 使用到的寄存器
- `dst_reg` 必须是结果寄存器
- 立即数操作数要写入 `operands[i].imm32` 或 `imm16`
- 如需附加的 nibble 级元信息，可放在 `call->reserved`

当前代码中：

- rotate/extract/endian/barrier 都只使用 `dst_reg` + `operands[]`
- select 额外把 condition code 放进 `call->reserved`

另外，当前 `bpf_kinsn_call.operands` 的容量是 4，这也是现阶段新增 kinsn 的显式操作数上限。

### 5.5 `model_call()` 的约定

`model_call()` 的职责不是描述“fallback kfunc 函数体做了什么”，而是描述“JIT inline 后的 kinsn 语义是什么”。

换句话说，必须以 emit 的 native 语义为准，而不是以 `__bpf_kfunc` fallback 的 C 代码形态为准。

这也是为什么：

- packed rotate 的结果寄存器可以不是 `r0`
- packed barrier 可以声明“无返回值且不 clobber 其他寄存器”
- packed endian 可以声明“从 base 指针读出结果”而不是“普通 call 返回一个值”

### 5.6 注册 API

内核提供：

```c
int bpf_register_kinsn_ops(const char *func_name,
			   const struct bpf_kinsn_ops *ops);
void bpf_unregister_kinsn_ops(const char *func_name);
```

注册时会检查：

- `func_name`、`ops`、`owner`、`model_call` 不能为空
- 至少有一个 emit callback
- `max_emit_bytes > 0`
- `supported_encodings != 0`
- 若支持 `BPF_KINSN_ENC_PACKED_CALL`，则 `decode_call` 不能为空

另外，`KF_KINSN` 不能与一组有资源语义/上下文语义的 kfunc flags 混用，见 `bpf_kinsn_forbidden_flags()`。

## 6. `bpf_kinsn_effect` 语义

### 6.1 结构体

```c
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
```

### 6.2 每个字段的含义

| 字段 | 含义 | verifier 如何使用 |
| --- | --- | --- |
| `input_mask` | 逻辑输入寄存器集合 | `bpf_kinsn_check_input_regs()` 要求其中的纯寄存器输入必须是 `SCALAR_VALUE` |
| `clobber_mask` | 会被这条 kinsn 改写或销毁的寄存器集合 | `bpf_kinsn_apply_clobber_mask()` 把非结果寄存器标成 not-init |
| `result_type` | `VOID` 或 `SCALAR` | 决定是否存在结果寄存器 |
| `result_reg` | 结果寄存器编号 | `bpf_kinsn_apply_result()` 更新它的状态 |
| `result_size` | 结果位宽，当前只允许 `4` 或 `8` | 用于设置 `subreg_def` |
| `nr_mem_accesses` | 本次 kinsn 的内存访问数 | 当前最多 2 |
| `flags` | effect flags，目前只有 `BPF_KINSN_EFFECT_HAS_TNUM` | 决定是否应用 `result_tnum` |
| `result_tnum` | 结果的位级不确定性信息 | 与现有寄存器状态求交 |
| `umin/umax/smin/smax` | 结果区间 | 与现有寄存器状态求交并做 sanity check |
| `mem_accesses[]` | 内存访问声明 | 进入 core memory access 校验 |

### 6.3 `bpf_kinsn_mem_access` 的含义

```c
struct bpf_kinsn_mem_access {
	u8 base_reg;
	u8 size;
	u8 access_type;
	u8 flags;
	s16 off;
};
```

| 字段 | 含义 | 当前约束 |
| --- | --- | --- |
| `base_reg` | 基址寄存器 | 必须是有效寄存器，且不能同时出现在 `clobber_mask` |
| `size` | 访问大小 | 只允许 `1/2/4/8` |
| `access_type` | `BPF_READ` 或 `BPF_WRITE` | 其他值无效 |
| `flags` | 访问附加语义 | 目前只支持 `BPF_KINSN_MEM_RESULT` |
| `off` | 固定偏移 | 直接传给 `check_mem_access()` |

### 6.4 verifier 对 effect 的硬性约束

`bpf_validate_kinsn_effect()` 当前会强制检查：

1. `input_mask` 只能引用有效寄存器
2. `clobber_mask` 只能引用有效寄存器
3. `clobber_mask` 不能包含 `r10`
4. 若 `result_type == SCALAR`
   - `result_reg` 必须有效且不是 `r10`
   - `result_reg` 必须出现在 `clobber_mask`
   - `result_size` 只能是 `4` 或 `8`
5. `nr_mem_accesses` 不能超过数组容量
6. memory base reg 不能同时被 clobber
7. 只有一个 memory read 可以被标记为 `BPF_KINSN_MEM_RESULT`
8. `BPF_KINSN_MEM_RESULT` 只能用于 read，且要求 `result_type == SCALAR`
9. packed ABI 下，`input_mask` / `clobber_mask` / `result_reg` / memory base reg 都必须来自显式解码的寄存器

### 6.5 verifier 如何应用 effect

可以把 core apply 理解成这几步：

1. 先对非结果寄存器应用 `clobber_mask`
2. 如果有 `BPF_KINSN_MEM_RESULT`
   - 先用 `check_mem_access()` 验证访问合法
   - 再把 load state 拷贝到结果寄存器
3. 如果没有 memory result
   - 结果寄存器先被标成 unknown scalar
4. 再对结果寄存器施加：
   - `result_tnum`
   - `umin/umax/smin/smax`
5. 最后根据 `result_size` 设置 `subreg_def`

这让 `model_call()` 可以表达两类完全不同的 kinsn：

- 纯 ALU kinsn：例如 rotate/select/extract
- memory kinsn：例如 endian_load

## 7. 安全模型

### 7.1 `kinsn` 安全性的真实边界

这里要先说清楚一个边界：`kinsn` module 是内核模块，不是用户态插件，也不是不可信沙箱代码。

所以安全目标不是“防御恶意 kernel module”，而是：

- 不把 verifier 内部状态裸露给 module
- 不允许 module 绕过 core memory checker
- 把 verifier/JIT 一致性问题收敛到一个受限 API 上

如果一个恶意内核模块故意撒谎，整个内核本来就已经是 trusted computing base 里的代码；这不是 `kinsn` API 试图解决的问题。`kinsn` 要解决的是“如何让扩展语义在框架层面不需要 verifier 特判，并尽量减少误建模面”。

### 7.2 为什么 module 不能通过 API 直接破坏 verifier safety

在框架层面，module 被限制在这几个出口：

- `decode_call()`：只能把 payload 解释成 `bpf_kinsn_call`
- `validate_call()`：只能拒绝非法编码
- `model_call()`：只能填写 `bpf_kinsn_effect`
- `emit_*()`：只能根据同一个 `bpf_kinsn_call` 发射代码

它做不到的事包括：

- 直接拿到 `struct bpf_reg_state *`
- 直接把某个寄存器标成 pointer-safe
- 直接跳过内存访问检查
- 直接绕过 verifier backtracking 逻辑

这些动作都仍然由 core 控制。

### 7.3 memory safety 仍由 core 保证

对 memory kinsn，module 只能声明：

- base reg 是哪个
- 访问大小是多少
- 是读还是写
- 哪个读结果应该成为返回值

真正的合法性判断仍然走：

- `check_mem_access()`
- load-state 建模
- 结果寄存器 bounds/tnum 合并

因此，memory kinsn 不能靠私有 callback 绕过现有 pointer/range 规则。

### 7.4 packed ABI 的额外安全约束

packed ABI 相比 legacy，多了几条额外约束：

1. sidecar 必须紧邻目标 `CALL`
2. sidecar 不能跨 subprog 边界被消费
3. sidecar 只能跟注册过的 `KF_KINSN` target 搭配
4. packed 下所有寄存器引用都必须由 `decode_call()` 显式暴露
5. `CALL.off` 不能被拿来塞 packed 操作数，因为它属于 module BTF FD slot
6. 一旦 verifier 选择了 kinsn path，JIT 不能 fallback 回普通 kfunc call

第 6 点尤其重要。因为很多 kinsn 的 verifier model 明确假定：

- 结果不一定在 `r0`
- 并不是所有 caller-saved 都会被 clobber
- 有的甚至根本没有返回值

如果此时 JIT 又偷偷发一个普通 `CALL`，verifier 模型会立刻失真。

### 7.5 `KF_KINSN` 与资源语义互斥

当前 `bpf_kinsn_forbidden_flags()` 明确排除了多类 flag，例如：

- `KF_ACQUIRE` / `KF_RELEASE`
- `KF_ITER_*`
- `KF_RCU*`
- `KF_SLEEPABLE`
- `KF_DESTRUCTIVE`
- `KF_FASTCALL`
- `KF_IMPLICIT_ARGS`
- `KF_ARENA_*`

这背后的原则很简单：`kinsn` 应该是“无资源语义、可局部建模”的内联指令抽象，而不是承载 refcount、sleep、iterator 或 arena 语义的高级 kfunc。

## 8. 现有 kinsn 清单

先给出总表，再分别说明。

| kinsn | packed payload | `model_call()` 核心 effect | 当前 x86 `emit_*()` | 备注 |
| --- | --- | --- | --- | --- |
| `bpf_rotate64` | `dst \| (src << 4) \| (shift << 8)` | 输入 `src`，结果/clobber `dst` | `mov dst, src` + `rol imm8, dst` | packed shift 是立即数 |
| `bpf_extract64` | `dst \| (start << 8) \| (len << 16)` | 输入 `dst`，结果/clobber `dst`，附带区间/tnum 缩窄 | `shr imm8, dst` + `and imm32, dst` | 当前不是 `BEXTR` |
| `bpf_select64` | `dst \| (true << 4) \| (false << 8) \| (cond << 12) \| (cc << 16)` | 输入 `true/false/cond`，结果/clobber `dst`，结果是两路 union | `mov/test/cmov` | 当前 `cc=0` 表示 `cond != 0` |
| `bpf_endian_load16/32/64` | `dst \| (base << 4)` | 输入 `base`，结果/clobber `dst`，声明一次 memory read | `load + byte swap` | 当前不是单条 `MOVBE` |
| `bpf_speculation_barrier` | `0` | 无输入、无结果、无 clobber | `lfence` | packed bytecode 比 legacy 多 1 条 |

### 8.1 `bpf_rotate64`

payload：

```text
bits [3:0]   dst_reg
bits [7:4]   src_reg
bits [15:8]  shift_amount
```

packed 语义：

- `dst = rotl(src, shift)`
- 若 `dst == src`，是原地 rotate
- 若 `shift == 0`，emit 不需要发 `ROL`

`model_call()`：

- packed：
  - `input_mask = BIT(src)`
  - `clobber_mask = BIT(dst)`
  - `result_reg = dst`
  - `result_size = 8`
- legacy：
  - 输入 `r1/r2`
  - 结果 `r0`
  - 额外 clobber `r4`

x86 emit：

- packed：可选 `mov dst, src`，然后 `rol imm8, dst`
- legacy：固定序列 `mov rax, rdi; mov rcx, rsi; rol rax, cl`

### 8.2 `bpf_extract64`

payload：

```text
bits [3:0]    dst_reg
bits [15:8]   start
bits [23:16]  len
```

packed 语义：

- 对 `dst` 原地执行 bit extract
- 当前 packed 只支持立即数 `start` 和 `len`

`model_call()`：

- packed：
  - `input_mask = BIT(dst)`
  - `clobber_mask = BIT(dst)`
  - `result_reg = dst`
  - `umax = (1 << len) - 1`（`len == 32` 时为 `U32_MAX`）
  - 若 `umax != U64_MAX`，填 `result_tnum`
- legacy：
  - 输入 `r1/r2/r3`
  - 结果 `r0`
  - 额外 clobber `r4`
  - `umax` 由 `scalar_regs[1]`/`scalar_regs[2]` 推导

x86 emit：

- packed：`shr imm8, dst` + `and imm32, dst`
- legacy：变量移位 + mask 构造序列

维护注意点：

- 当前实现并没有发 `BEXTR`
- 抽象上允许未来改成 `BEXTR`，只要 `model_call()` 不变且 verifier 语义一致

### 8.3 `bpf_select64`

payload：

```text
bits [3:0]    dst_reg
bits [7:4]    true_reg
bits [11:8]   false_reg
bits [15:12]  cond_reg
bits [19:16]  cond_code
```

当前 `cond_code == 0`，表示 “`cond != 0` 时取 true_reg，否则取 false_reg”。

`model_call()`：

- 输入是 `true/false/cond`
- 结果/唯一 clobber 是 `dst`
- 如果 `cond` 是编译期常量，结果直接退化成其中一路
- 否则把 true/false 两路的 `tnum` 和区间做 union

x86 emit：

- 如果 `dst` 既不是 `true_reg` 也不是 `false_reg`，先 `mov dst, false`
- `test cond, cond`
- 正常情况发 `cmovnz dst, true`
- 若 `dst == true_reg`，则改发 `cmovz dst, false`

这也是一个很好的例子：`model_call()` 描述的是“条件选择”的抽象语义，不关心 emit 最后是 `cmovnz` 还是 `cmovz`。

### 8.4 `bpf_endian_load16/32/64`

payload：

```text
bits [3:0]  dst_reg
bits [7:4]  base_reg
```

当前 packed payload 不编码内存 offset。原因是：

- `CALL.off` 必须留给 module fd slot
- `endian` pass 需要尽量保留 verifier 已证明的 pointer range 在真实 base reg 上

所以 daemon 采取的是：

- `offset == 0`：直接 `sidecar + CALL`
- `offset != 0`：先临时 `ADD` base reg 或复制后 `ADD`，再发 packed call

`model_call()`：

- `input_mask = BIT(base_reg)`
- `clobber_mask = BIT(result_reg)`
- `result_type = SCALAR`
- `nr_mem_accesses = 1`
- `mem_accesses[0]` 是一次 `BPF_READ`
- `mem_accesses[0].flags = BPF_KINSN_MEM_RESULT`

结果范围：

- 16-bit load：`[0, 65535]`，`result_size = 8`
- 32-bit load：`[0, U32_MAX]`，`result_size = 4`
- 64-bit load：`[0, U64_MAX]`，`result_size = 8`

x86 emit：

- 16-bit：`movzx` + `rol16 8`
- 32-bit：`mov` + `bswap32`
- 64-bit：`mov` + `bswap64`

维护注意点：

- 当前实现不是单条 `MOVBE`
- 抽象允许将来在某些 arch 上用单条 fused 指令替换，只要 effect 不变

### 8.5 `bpf_speculation_barrier`

payload：

```text
0
```

`validate_call()` 要求 packed payload 必须全零。

`model_call()`：

- `result_type = VOID`
- 不声明任何 input 或 clobber

x86 emit：

- 单条 `lfence`

这条 kinsn 很能说明 kinsn 的价值：

- 普通 kfunc call 语义会把它当成会破坏 caller-saved 的调用点
- `kinsn` 语义可以准确表达 “这是一个 barrier，不是函数调用”

## 9. 如何添加新 kinsn

下面给出面向贡献者的实际步骤。假设你要新增一个 `foo` kinsn。

1. 先定义抽象语义，而不是先写 emit。
   - 明确输入寄存器、结果寄存器、是否有 memory access、结果范围、是否需要 packed。
   - 如果它带 refcount、sleep、iterator、arena 等语义，通常不应做成 kinsn。

2. 在 `module/x86/`（或对应架构目录）新增 module 文件。
   - 写 `__bpf_kfunc` fallback 定义。
   - 写 `KINSN_KFUNC_SET(...)` 或多 kfunc 版本。

3. 设计 packed payload。
   - 尽量让 packed 直接表达真正的目标语义。
   - 不要占用 `CALL.off`。
   - 让 `decode_call()` 能显式列出所有寄存器依赖。
   - 当前 `bpf_kinsn_call.operands[4]` 限制了最多 4 个显式操作数。

4. 实现 `decode_call()`。
   - legacy 可以直接返回 0。
   - packed 必须把 `payload -> bpf_kinsn_call` 规范化。
   - 如有保留位，写入 `call->reserved`。

5. 实现 `validate_call()`。
   - 检查立即数范围、保留位、操作数组合是否合法。
   - 这里拒绝得越早，后面越清晰。

6. 实现 `model_call()`。
   - 只填 `bpf_kinsn_effect`，不要假设自己能改 verifier state。
   - memory kinsn 一定要走 `mem_accesses[]`，不要偷懒把 pointer 当 scalar。
   - 该填 `result_tnum` 的要填，否则会丢 verifier precision。

7. 实现 `emit_x86()` / `emit_arm64()`。
   - 输入必须只依赖 `bpf_kinsn_call`。
   - 返回值必须等于真正写入的长度。
   - `max_emit_bytes` 要给出安全上界。

8. 用 `DEFINE_KINSN_MODULE()` 或 `DEFINE_KINSN_MODULE_MULTI()` 注册。
   - 单 kfunc module 用前者。
   - 多 kfunc module（如 endian 这种族）用后者。

9. 更新 daemon。
   - 在 `daemon/src/kfunc_discovery.rs` 把 kfunc 名和 module 名加到发现表里。
   - 在 `daemon/src/pass.rs` 的 `KfuncRegistry` 中增加对应能力字段/映射。
   - 在 `daemon/src/passes/` 新增或修改 pass，使用 `emit_packed_kfunc_call_with_off()` 发出 sidecar + CALL。
   - 如果该 kinsn 只能在某些站点上 packed，需要像 `endian` 一样显式做站点级 gating。

10. 补测试。
   - daemon unit test：payload 构造、站点匹配、skip 条件
   - kernel/unit selftest：正例 apply、负例 reject、reg preserve、range narrowing
   - 若是 memory kinsn，必须覆盖 invalid access reject

### 9.1 建议的 reviewer checklist

新增 kinsn 时，reviewer 至少要看这几件事：

- `decode_call()` 与 daemon payload 布局是否完全一致
- `model_call()` 与 `emit_*()` 是否描述的是同一个语义
- packed 下所有实际使用到的寄存器是否都被显式 decode
- 是否错误地把 memory kinsn 建模成纯 scalar kinsn
- 是否遗漏 `result_tnum` / bounds 缩窄
- `max_emit_bytes` 是否覆盖最坏路径

## 10. 对比 Legacy ABI

### 10.1 两种 ABI 的根本差别

kernel 目前仍支持两种编码：

- `BPF_KINSN_ENC_LEGACY_KFUNC`
- `BPF_KINSN_ENC_PACKED_CALL`

但它们的目标完全不同：

| ABI | 输入来源 | 结果寄存器 | `CALL.off` 用途 | daemon 当前是否生成 |
| --- | --- | --- | --- | --- |
| legacy | `r1-r5` | 默认 `r0` | module BTF FD slot | 否 |
| packed | sidecar payload | 由 `dst_reg` 显式指定 | module BTF FD slot | 是 |

### 10.2 典型指令数对比

下表说的是 daemon 在字节码层面“典型会生成什么”，不是某个理论最优手写程序的绝对下界。

| kinsn | legacy 典型形式 | 典型 BPF 指令数 | packed 典型形式 | 典型 BPF 指令数 |
| --- | --- | ---: | --- | ---: |
| rotate | `mov r1,val; mov r2,shift; call; mov dst,r0`，常伴随 spill/fill | 4 + spill/fill | `sidecar; call` | 2 |
| extract | `mov r1,val; mov r2,start; mov r3,len; call; mov dst,r0` | 5 | `sidecar; call` | 2 |
| select | `mov r1,a; mov r2,b; mov r3,cond; call; mov dst,r0` | 5 | `sidecar; call` | 2 |
| endian | `mov r1,addr; call; mov dst,r0` | 3 | `sidecar; call`，非零 offset 时可能额外 `mov/add` | 2 到 4 |
| barrier | `call` | 1 | `sidecar(0); call` | 2 |

### 10.3 性能差异

packed 的收益主要不在“CALL 指令本身变少”，而在“围绕 CALL 的 ABI 杂音消失”：

- 不需要把输入搬到 `r1-r5`
- 不需要把结果再从 `r0` 搬回真正目标寄存器
- 不再依赖通用 caller-saved spill/fill 模板
- verifier 能精确知道谁被 clobber，backtracking 不必按普通 call 处理

对 rotate/select/extract 来说，这通常直接减少 BPF 指令数、native 指令数和寄存器压力。

对 endian 来说，收益更偏向：

- 保留统一 packed ABI
- 允许直接把结果写入目标寄存器
- 配合 memory result effect 保留 verifier 精度

对 barrier 来说，packed 在 BPF 字节码层面甚至更大，但它换来的是“精确 barrier 语义而不是普通函数调用语义”。

### 10.4 为什么 legacy 已从 daemon 路径删除

这里要精确表述：

- **删除的是 daemon 对 legacy ABI 的常规发射路径**
- **没有删除 kernel 对 `BPF_KINSN_ENC_LEGACY_KFUNC` 的兼容支持**

daemon 不再生成 legacy 的原因有四个：

1. legacy 违背 packed kinsn 的核心目标。
   - 它仍然是 `r1-r5/r0` 风格的调用 ABI，arg setup 和 result move 都在。

2. legacy 与 module kfunc 的现实约束相冲突。
   - `CALL.off` 已经必须承担 module BTF FD slot。
   - packed sidecar 让 operand payload 和 module fd 两件事彻底分离。

3. legacy 会把 verifier/JIT 语义重新拖回“普通 call 近似”。
   - 特别是对 barrier、in-place update、direct-dst result 这类语义不自然。

4. 一旦系统已经要求 verifier 和 JIT 走 kinsn path，继续保留 daemon 侧 legacy fallback 只会增加维护面。
   - 当前实现更直接：packed 不可用就 skip，不生成一个次优又更复杂的 ABI。

因此，当前代码的取舍是：

- kernel 保留 legacy 兼容，便于手写程序、过渡期兼容和框架健壮性
- daemon 只生成 packed，避免把旧 ABI 再扩散回新路径

## 11. 验证方法

### 11.1 当前 selftest 覆盖点

`tests/unittest/rejit_kinsn_packed.c` 当前至少覆盖了这些点：

- `packed_kinsn_discovery`
  - 验证 module BTF、kfunc BTF ID 和 fd_array 发现链路
- `packed_rotate_apply`
  - 验证 sidecar payload -> rotate decode -> JIT apply
- `packed_select_apply`
  - 验证 direct-dst select 路径
- `packed_endian_apply`
  - 验证 memory result effect 与 endian load 路径
- `packed_barrier_preserves_r5`
  - 验证 barrier 不会被按普通 call 的 clobber 语义处理
- `packed_extract_range_narrowing`
  - 验证 extract 的 result bounds/tnum 缩窄足以影响后续 verifier 接受性

### 11.2 `packed_extract_range_narrowing` 为什么重要

这是当前 packed ABI 测试里最精巧的一项。

测试大意是：

```text
r2 = 0xabcd
r2 = extract(r2, 0, 8)   // 逻辑上只保留低 8 bit
r1 = fp
r1 += -256
r1 += r2
*(u8 *)(r1 + 0) = 1
```

它验证的是：`model_extract_call()` 必须把结果精确缩窄到 `[0, 255]`，否则 verifier 会把 `r1 += r2` 看成潜在越界的 stack pointer 偏移。

为什么这很关键：

- 如果 extract 只被建模成“未知标量”
  - `r2` 可能是任意 `u64`
  - `fp - 256 + r2` 无法证明仍落在合法 stack 范围
  - 后续 `ST_MEM` 会被 reject
- 如果 extract 被正确建模成“低 8 bit”
  - `r2 ∈ [0, 255]`
  - `fp - 256 + r2` 恰好落在 `fp-256 ... fp-1`
  - 程序应被 accept

也就是说，这个测试不是在验证“extract 算出来是不是对”，而是在验证：

- packed decode 是否正确
- `model_call()` 是否给出了足够强的区间/tnum
- core apply 是否真的把这些信息传播到了后续指针运算

这是 kinsn 设计里最值得长期保留的精度回归测试之一。

### 11.3 建议的持续验证策略

对每个新 kinsn，建议至少补齐三类测试：

1. 编码一致性测试
   - daemon payload 构造
   - module `decode_call()`
   - JIT `bpf_jit_get_kinsn_call()`

2. 语义一致性测试
   - `model_call()` 结果与真实 emit 语义一致
   - direct-dst、in-place、边界立即数等角落情况

3. verifier precision / safety 测试
   - 结果范围缩窄
   - clobber preserve
   - memory access reject/accept

如果一个新 kinsn 同时修改了寄存器和内存，测试必须同时覆盖这两面；只测运行结果，不测 verifier 接受性，是不够的。

# kinsn FUNC-id Transport 重构设计

日期：2026-03-25  
状态：proposed rework against current `vendor/linux-framework/rejit-v2`

## 0. 文档目的

本文档回答两个问题：

1. 当前 `vendor/linux-framework/rejit-v2` 相对 kernel 上游 `origin/master` 的 diff 里，哪些是 REJIT 核心，哪些是 `kinsn transport` 带来的额外表面积。
2. 在不改变 `kinsn` 当前寄存器约定、`proof lowering` 语义、native emit 语义的前提下，怎样把 `kinsn` 从今天的 `VAR-id + 独立注册表` 收敛成 `FUNC-id transport`。

本文档的推荐方案不是“把 `kinsn` 变成普通 kfunc”，而是：

- 保留 `PSEUDO_KINSN_CALL`
- 保留 sidecar payload
- 保留 verifier 的 `proof lowering / restore`
- 保留 x86/arm64 native emit
- 仅把 target identity 从 `BTF_KIND_VAR` 收敛到 `BTF_KIND_FUNC`
- 最大化复用 kfunc 的 `module BTF / fd_array / func_id` 解析路径

一句话定义：

`kinsn` 继续保持自己的 call ABI 和 verifier 语义，只把“我是谁”这件事从 `VAR id` 改成 `FUNC id`。

## 1. 基线：当前相对上游的 kernel diff

对比基线：

- 仓库：`vendor/linux-framework`
- 当前分支：`rejit-v2`
- 上游基线：`origin/master`
- merge-base：`c23719abc3308df7ed3ad35650ad211fb2d2003d`

当前统计：

| 指标 | 数值 |
|------|------|
| 修改文件数 | 22 |
| 新增行数 | +2205 |
| 删除行数 | -47 |
| 净增行数 | +2158 |

主要文件分布：

| 文件 | 变化 | 说明 |
|------|------|------|
| `kernel/bpf/syscall.c` | +696/-1 | REJIT 主实现 |
| `kernel/bpf/verifier.c` | +649/-32 | REJIT + kinsn verifier + desc cache |
| `kernel/bpf/btf.c` | +239/-1 | kinsn `VAR` 注册/lookup |
| `kernel/bpf/bpf_struct_ops.c` | +108/-0 | struct_ops refresh |
| `include/linux/bpf.h` | +110/-0 | REJIT + kinsn 核心声明 |
| `arch/x86/net/bpf_jit_comp.c` | +54/-3 | x86 native emit |
| `arch/arm64/net/bpf_jit_comp.c` | +38/-0 | arm64 native emit |
| `scripts/Makefile.btf` | +3/-1 | 为 extmod BTF `global_var` 放宽 |
| `include/uapi/linux/bpf.h` | +24/-0 | `BPF_PROG_REJIT` + `PSEUDO_KINSN_*` |

这些变化里，`REJIT` 核心和 `kinsn transport` 不是同一件事。

必须保留的大块：

- `BPF_PROG_REJIT` syscall 主路径
- trampoline / dispatcher / struct_ops refresh
- `orig_prog_insns` / GET_ORIGINAL 能力
- proof lowering / restore
- x86 / arm64 native emit

可收敛的主要表面积：

- `BTF_KIND_VAR` 作为 kinsn identity
- `register_bpf_kinsn_set()` / `unregister_bpf_kinsn_set()`
- `btf->kinsn_tab`
- `prog->aux->kinsn_tab`
- `scripts/Makefile.btf` 里的 `global_var` 兼容 hack
- daemon 侧对 descriptor `VAR` 的扫描和发现

## 2. 当前实现的问题

### 2.1 当前 transport 建模

当前实现里：

- `CALL.src_reg = BPF_PSEUDO_KINSN_CALL`
- `CALL.imm = module BTF 中某个 `struct bpf_kinsn` descriptor 的 `BTF_KIND_VAR` id`
- `CALL.off = module BTF fd slot`
- `sidecar` 承载 packed payload

module 侧通过 `register_bpf_kinsn_set()` 注册：

- `descriptor var name -> const struct bpf_kinsn *`

verifier load 时通过：

- `offset -> module BTF`
- `(btf, var_id) -> struct bpf_kinsn *`

拿到 descriptor。

### 2.2 这套方案为什么让 diff 变重

当前实现虽然已经复用了 `offset -> module BTF` 这段 kfunc 路径，但后半段又复制了一套独立机制：

- BTF 里单独挂 `btf->kinsn_tab`
- 单独的 `register_bpf_kinsn_set()`
- 单独的 `btf_try_get_kinsn_desc()`
- verifier 里单独的 `add_kinsn_call()` / `find_kinsn_desc()`
- prog aux 里单独的 `kinsn_tab`
- daemon 里按 `BTF_KIND_VAR` 扫 descriptor 名字

结果是：

1. transport 身份和现有 kfunc 身份体系脱节  
2. extmod BTF 还要为 `global_var` 改构建链  
3. verifier/JIT/prog lifetime 里多出一套并行 desc cache  
4. upstream review 会看到一个“平行 kinsn 子系统”

### 2.3 为什么不能直接切成 `PSEUDO_KFUNC_CALL`

问题不在于 `FUNC id` 本身，而在于 call ABI。

普通 kfunc 路径会进入：

- `check_kfunc_call()`
- `fixup_kfunc_call()`

这两条路径默认假设：

- 标准 kfunc 参数/返回语义
- caller-saved clobber
- `r0` 返回值建模
- 普通 kfunc fixup / call-imm rewrite

而 `kinsn` 当前明确不是这套语义：

- 它靠 sidecar 提供 operand/payload
- verifier 语义来自 `proof lowering / restore`
- native emit 不是普通 kfunc call emit

所以，若直接改成 `PSEUDO_KFUNC_CALL`，就必须在普通 kfunc 路径里到处加 `if (is_kinsn)` 守卫。这会把 generic kfunc 代码弄脏。

## 3. 设计目标

必须满足：

1. 不改变 `kinsn` 当前 call ABI  
2. 不改变寄存器约定  
3. 不改变 sidecar payload 编码  
4. 不改变 proof lowering / restore 模型  
5. 不改变 native emit 模型  
6. 删除 `BTF_KIND_VAR + global_var` 这条 transport 依赖  
7. 尽量删掉独立的 kinsn 注册/lookup/cache 代码  
8. 不把普通 kfunc verifier/fixup 路径污染成“双语义”

明确不做：

1. 不把 `kinsn` 变成普通 kfunc 参数传递语义  
2. 不靠修改 testcase 规避内核问题  
3. 不为了 transport 重写 REJIT 主路径  
4. 不保留 v1 兼容壳

## 4. 方案比较

### 4.1 方案 A：维持现状

定义：

- `PSEUDO_KINSN_CALL + VAR id`
- 独立 `register_bpf_kinsn_set()`
- 独立 `btf->kinsn_tab`

优点：

- 当前已经工作
- 不需要改 daemon / module ABI

缺点：

- diff 面最大
- `global_var` 依赖最重
- verifier/prog lifetime 里有平行子系统
- upstream 叙事最差

结论：

不推荐继续扩展。

### 4.2 方案 B：切到 `PSEUDO_KFUNC_CALL + FUNC id + KF_KINSN`

定义：

- transport 直接并入 `PSEUDO_KFUNC_CALL`
- 引入内部 `KF_KINSN`
- 普通 kfunc 路径里识别并旁路到 `kinsn` 语义

优点：

- identity 和 carrier 最统一
- 长期上最像“完全并回 kfunc transport”

缺点：

- generic `check_kfunc_call()` / `fixup_kfunc_call()` / JIT call 分支都要知道 `KF_KINSN`
- 容易把普通 kfunc 路径污染成双语义
- 当前 call ABI 明显不同，代码审查会一直追问“既然不是 kfunc ABI，为何用 kfunc opcode”

结论：

长期可能成立，但不是当前最干净的收敛点。

### 4.3 方案 C：保留 `PSEUDO_KINSN_CALL`，切成 `FUNC id transport`

定义：

- `CALL.src_reg` 继续是 `BPF_PSEUDO_KINSN_CALL`
- `CALL.imm` 从 `VAR id` 改成 `FUNC id`
- `CALL.off` 继续表示 module BTF fd slot
- verifier 继续在 `proof lowering` 前解析 descriptor
- 普通 `check_kfunc_call()` / `fixup_kfunc_call()` 不知道 `kinsn`

优点：

- `kinsn` call ABI 完全不变
- generic kfunc 语义路径不被污染
- `FUNC id` / module BTF / `fd_array` / `find_kfunc_desc_btf()` 这层可直接复用
- 可以删掉 `global_var` 依赖
- 代码叙事更清楚：`kinsn` 不是 kfunc，只是借用 kfunc identity

缺点：

- 仍然保留单独 opcode
- 仍然需要一层 `func_id -> struct bpf_kinsn *` 元数据
- 不是“完全并入 kfunc”

结论：

这是当前最好的收敛方案，也是本文档的推荐方案。

## 5. 推荐设计

## 5.1 外部指令 ABI

保留：

- `BPF_PSEUDO_KINSN_SIDECAR`
- `BPF_PSEUDO_KINSN_CALL`

改变：

- `CALL.imm` 不再是 `struct bpf_kinsn` descriptor 的 `BTF_KIND_VAR` id
- `CALL.imm` 改成 kinsn stub symbol 的 `BTF_KIND_FUNC` id

不变：

- `CALL.off = module BTF fd slot`
- packed sidecar payload
- 原始 `kinsn` 的寄存器约定

所以 ABI 变化是：

- opcode 不变
- sidecar 不变
- call ABI 不变
- 只有 `imm` 的身份语义从 `VAR id` 变成 `FUNC id`

## 5.2 模块侧建模

每个 kinsn 继续保留自己的 descriptor：

```c
static const struct bpf_kinsn bpf_rotate64_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = ...,
	.max_emit_bytes = ...,
	.instantiate_insn = ...,
	.emit_x86 = ...,
};
```

但同时引入一个真实的 stub symbol：

```c
__bpf_kfunc void bpf_rotate64(void) { }
```

用途不是执行，而是提供：

- `BTF_KIND_FUNC`
- `func_id`
- module BTF 里的稳定名字
- 复用 `register_btf_kfunc_id_set()`

module 注册分两层：

1. 真实 kfunc ID set  
2. kinsn companion metadata set

推荐 companion 结构：

```c
struct bpf_kinsn_func_id {
	const char *func_name;
	const struct bpf_kinsn *desc;
};

struct bpf_kinsn_func_set {
	struct module *owner;
	u32 cnt;
	const struct bpf_kinsn_func_id *ids;
};
```

这里的关键点是：

- companion set 不再依赖 `BTF_KIND_VAR`
- 也不要求 extmod BTF 有 `global_var`
- 它只是把 `FUNC name / FUNC id` 绑定到 `struct bpf_kinsn *`

换句话说，保留一层薄 metadata 是合理的；要删除的是“BTF VAR 充当 descriptor identity”这条重机制。

## 5.3 kernel 侧 lookup 结构

保留可复用部分：

- `find_kfunc_desc_btf(env, offset)`
- module BTF fd 获取
- module lifetime pin
- split-BTF 下的 `offset -> struct btf *`

删除当前这条链：

- `register_bpf_kinsn_set()`
- `unregister_bpf_kinsn_set()`
- `btf->kinsn_tab`
- `btf_try_get_kinsn_desc()`

替换为：

- `btf_try_get_kinsn_desc_by_func_id()` 或等价 helper
- 输入为 `(btf, func_id)`
- 输出为 `const struct bpf_kinsn *`

实现要求：

1. `func_id` 对应的 BTF type 必须是 `BTF_KIND_FUNC`
2. 该 `func_id` 必须在 companion set 里有 desc
3. desc 必须满足：
   - `owner` 匹配 module
   - `instantiate_insn != NULL`
   - `max_insn_cnt != 0`

## 5.4 verifier 行为

保留：

- `PSEUDO_KINSN_CALL` 只允许在 `proof lowering` 之前被消费
- `do_check_insn()` 若仍看到 `PSEUDO_KINSN_CALL`，继续视为 internal error
- `lower_kinsn_proof_regions()` / `restore_kinsn_proof_regions()` 主模型不变

改变：

- `fetch_kinsn_desc_meta()` 的输入从 `(var_id, offset)` 变成 `(func_id, offset)`
- 先通过 `find_kfunc_desc_btf()` 拿 module BTF
- 再通过 `func_id -> desc` companion metadata 拿 `struct bpf_kinsn *`

重要的是：

- 不进入 `check_kfunc_call()`
- 不进入 `fixup_kfunc_call()`
- 不让普通 kfunc 的寄存器 clobber 规则污染 `kinsn`

## 5.5 JIT 行为

JIT 语义保持不变：

- x86 / arm64 仍按 `PSEUDO_KINSN_CALL` 识别
- 仍通过 `bpf_jit_get_kinsn_payload()` 和 desc 获取 payload + emit hook
- 仍直接发 native emit

变化只在 desc lookup：

- 不再查 `prog->aux->kinsn_tab` 里以 `VAR id` 为 key 的项
- 改成查以 `FUNC id` 为 key 的 kinsn desc cache

这层可以有两种实现：

1. 保留一个单独的 per-prog `kinsn_tab`，但 key 从 `VAR id` 改成 `FUNC id`
2. 进一步把 per-prog `kfunc_tab` / `kinsn_tab` 并成通用 `call_desc_tab`

推荐顺序：

- 第一阶段先只改 key 语义，降低风险
- 第二阶段再考虑把 per-prog desc cache 合并

## 6. 对上游 diff 的影响

### 6.1 会保留的改动

这些属于 REJIT 核心，不因为 transport 收敛而消失：

- `kernel/bpf/syscall.c`
- `kernel/bpf/trampoline.c`
- `kernel/bpf/dispatcher.c`
- `kernel/bpf/bpf_struct_ops.c`
- `kernel/bpf/core.c`
- `net/core/filter.c`
- `kernel/bpf/verifier.c` 里的 proof lowering / restore
- `arch/x86/net/bpf_jit_comp.c`
- `arch/arm64/net/bpf_jit_comp.c`

### 6.2 明确应该缩小或删除的改动

#### 6.2.1 `scripts/Makefile.btf`

当前只为 extmod `global_var` 放宽：

- 这属于 `VAR-id transport` 的副作用
- 切成 `FUNC id` 后应该完全删除

这是最直接、最干净的一项 diff 回收。

#### 6.2.2 `kernel/bpf/btf.c`

当前的 `btf_kinsn_tab` / register / unregister / `btf_try_get_kinsn_desc()` 主要服务于：

- `VAR id -> desc`

切成 `FUNC id` 后：

- 旧 `VAR` 解析和 `btf_type_is_kinsn_desc()` 可以删除
- register/unregister 逻辑会缩成一层更薄的 `func_id -> desc` companion metadata

所以 `btf.c` 依然可能有少量 kinsn 代码，但会从“独立 BTF 子系统”降到“薄 metadata 绑定层”。

#### 6.2.3 `include/linux/btf.h`

应该删除或收缩：

- `btf_try_get_kinsn_desc()` 的 `VAR` 语义声明

替换成：

- 一个明确以 `FUNC id` 为输入的 helper

#### 6.2.4 `include/linux/bpf.h`

应删除或替换：

- `struct bpf_kinsn_id`
- `struct bpf_kinsn_set`
- `register_bpf_kinsn_set()` / `unregister_bpf_kinsn_set()`

替换为：

- `struct bpf_kinsn_func_id`
- `struct bpf_kinsn_func_set`
- 与 companion metadata 绑定相关的薄 helper

#### 6.2.5 daemon 的发现逻辑

当前：

- 按 descriptor `VAR` 名字查 `BTF_KIND_VAR`

目标：

- 按 stub function 名字查 `BTF_KIND_FUNC`

这会删掉一整条“descriptor variable discovery”逻辑，跟上游也更一致，因为：

- kfunc/kallsyms/BTF 世界天然是围绕 function symbol 工作的
- 不是围绕某个描述符变量

## 7. file-by-file 迁移计划

## 7.1 kernel

### `include/uapi/linux/bpf.h`

保留：

- `BPF_PSEUDO_KINSN_CALL`
- `BPF_PSEUDO_KINSN_SIDECAR`

修改：

- 注释从“`imm == BTF_KIND_VAR of struct bpf_kinsn`”改成“`imm == BTF_KIND_FUNC of registered kinsn stub`”

### `tools/include/uapi/linux/bpf.h`

与 kernel UAPI 副本同步。

### `include/linux/bpf.h`

保留：

- `struct bpf_kinsn`
- sidecar helper

删除：

- `struct bpf_kinsn_id`
- `struct bpf_kinsn_set`
- `register_bpf_kinsn_set()`
- `unregister_bpf_kinsn_set()`

新增：

- `struct bpf_kinsn_func_id`
- `struct bpf_kinsn_func_set`

### `include/linux/btf.h`

删除：

- `btf_try_get_kinsn_desc(... var_id ...)`

新增：

- `btf_try_get_kinsn_desc_by_func_id(... func_id ...)`

### `kernel/bpf/btf.c`

删除：

- `btf_type_is_kinsn_desc()`
- `btf_resolve_kinsn_desc_id()`
- `register_bpf_kinsn_set()`
- `unregister_bpf_kinsn_set()`
- `btf->kinsn_tab` 的 `VAR-id` 版本

新增或替换：

- 以 `FUNC id` 为 key 的 companion metadata 绑定

### `kernel/bpf/verifier.c`

修改：

- `fetch_kinsn_desc_meta()` 改成按 `func_id` 查
- `add_kinsn_call()` 的 key 从 `VAR id` 改成 `FUNC id`
- `find_kinsn_desc()` / JIT payload query 的 key 同步切换

保留：

- `lower_kinsn_proof_regions()`
- `restore_kinsn_proof_regions()`
- `PSEUDO_KINSN_CALL` 在 `do_check_insn()` 里仍然不能落入正常 verifier 主路径

### `kernel/bpf/core.c` / `kernel/bpf/syscall.c`

如果继续保留单独 per-prog `kinsn_tab`：

- 仅同步其 key 语义和释放路径

如果进一步并 tab：

- 再做第二阶段 refactor

### `arch/x86/net/bpf_jit_comp.c`

不改 call ABI，仅改 desc lookup 取 key 的语义。

### `arch/arm64/net/bpf_jit_comp.c`

同上。

### `scripts/Makefile.btf`

删除 extmod `global_var` 特判。

## 7.2 module

### `module/include/kinsn_common.h`

当前 `DEFINE_KINSN_V2_MODULE(...)` 只会注册 descriptor set。

改为：

- 为每个 kinsn 声明 stub kfunc
- 定义 `BTF_KFUNCS_START(...)`
- 调用 `register_btf_kfunc_id_set()`
- 同时注册 companion `func_name -> desc` metadata

这里建议新增新的 module helper 宏，避免旧 API 继续存活。

### `module/x86/*.c`

每个模块都要：

1. 保留 `*_desc`
2. 新增 `__bpf_kfunc void <name>(void)` stub
3. 在 kfunc ID set 里注册该 stub
4. 在 companion metadata set 里把 stub 名字绑定到 desc

## 7.3 daemon

### `daemon/src/kfunc_discovery.rs`

当前：

- `KNOWN_KINSNS` 里存的是 descriptor variable name
- discovery 查 `BTF_KIND_VAR`

改为：

- `KNOWN_KINSNS` 里存 stub function name
- discovery 查 `BTF_KIND_FUNC`

保留：

- split-BTF 的 `base_str_off` / `type_id_bias`
- module BTF fd 的获取和持有

删除：

- 只为 `VAR` 准备的描述和日志

### `daemon/src/insn.rs`

保留：

- `BPF_PSEUDO_KINSN_CALL`
- sidecar 编码

不需要切到 `PSEUDO_KFUNC_CALL`。

## 7.4 tests

### `tests/unittest/rejit_kinsn.c`

修改：

- 单测里的 target ID 不再是假设 descriptor `VAR id`
- 改成 stub `FUNC id`

不应修改 testcase 语义，只改 transport identity 假设。

### kernel selftests / helpers

若有注释或 debug 输出写死 `VAR id`，同步更正。

## 8. ABI 影响

## 8.1 不变的 ABI

- `PSEUDO_KINSN_CALL`
- `PSEUDO_KINSN_SIDECAR`
- sidecar payload 格式
- `kinsn` 寄存器约定
- verifier `proof lowering` 语义
- native emit 语义

## 8.2 会变化的 ABI

- `CALL.imm` 的解释从 `BTF_KIND_VAR` 变成 `BTF_KIND_FUNC`
- module 注册接口不再是 `register_bpf_kinsn_set()`
- daemon 的 discovery 目标从 descriptor var name 变成 stub function name

## 8.3 为什么这仍然是可接受的 ABI 变化

因为这里变的是 transport identity，不是 `kinsn` 的行为 ABI。

从用户和 JIT 语义层面看：

- 程序看到的 sidecar 和 `kinsn` 语义没变
- verifier 证明模型没变
- JIT 发出的机器码没变

变化只发生在：

- loader 如何找到目标
- kernel 如何把一个 BTF id 解析成 `struct bpf_kinsn *`

## 9. 风险与对策

### 风险 1：仍然保留单独 opcode，会不会继续显得“像平行子系统”

会，但比今天轻很多。

因为真正重的部分不是 opcode，而是：

- `VAR-id identity`
- `global_var` 构建链依赖
- `btf->kinsn_tab`
- 独立 register/unregister

删掉这些之后，`PSEUDO_KINSN_CALL` 更像“自定义 transport opcode”，不是完整平行系统。

### 风险 2：是否还需要单独 per-prog `kinsn_tab`

短期允许保留。

先完成：

- `VAR id -> FUNC id`
- `global_var` 依赖删除
- module/daemon discovery 切换

再决定第二阶段是否把 `kfunc_tab` / `kinsn_tab` 并表。

### 风险 3：module companion metadata 是否仍然算“重复注册”

是，但这是薄 metadata，不是今天这种基于 `BTF_KIND_VAR` 的第二套 transport 身份系统。

关键差别是：

- 主 identity 已经是 `FUNC id`
- BTF/module lifetime 已经复用 kfunc 路径
- companion metadata 只负责把 `FUNC id` 绑定到 `struct bpf_kinsn *`

## 10. 推荐实施顺序

### 阶段 1：切 transport identity

目标：

- `PSEUDO_KINSN_CALL + FUNC id`
- module 用 stub function + `register_btf_kfunc_id_set()`
- daemon 用 `BTF_KIND_FUNC` discovery

完成标准：

- 旧的 `VAR id` 路径不再被新代码使用
- `vm-selftest` / `vm-test` / `vm-negative-test` 通过

### 阶段 2：删除旧 `VAR` 子系统

删除：

- `register_bpf_kinsn_set()`
- `btf->kinsn_tab`
- `btf_try_get_kinsn_desc()`
- `scripts/Makefile.btf` 的 `global_var` hack
- daemon 的 `VAR` 发现逻辑

完成标准：

- 树上不再有任何 kinsn transport 对 `BTF_KIND_VAR` 的依赖

### 阶段 3：按需要再合并 per-prog desc cache

这一步不是 transport 收敛的前提。

只有在阶段 1/2 稳定以后，再决定是否把：

- `prog->aux->kfunc_tab`
- `prog->aux->kinsn_tab`

进一步收成通用 `call_desc_tab`。

## 11. 最终结论

当前最好的方案不是维持 `VAR-id`，也不是立即把 `kinsn` 塞进 `PSEUDO_KFUNC_CALL`。

最好的方案是：

- 保留 `PSEUDO_KINSN_CALL`
- 保留当前 `kinsn` call ABI
- 保留 sidecar / proof lowering / native emit
- 把 `CALL.imm` 从 `VAR id` 改成 `FUNC id`
- 用真实 stub kfunc + `register_btf_kfunc_id_set()` 复用 kfunc identity
- 删除 `global_var` 依赖和大部分独立 kinsn 注册子系统

这样做的效果是：

- 不改 `kinsn` 语义
- 不污染普通 kfunc verifier/fixup 路径
- 明显缩小与上游的 transport diff
- 比当前实现更容易审，也更容易解释

这就是推荐的目标设计。

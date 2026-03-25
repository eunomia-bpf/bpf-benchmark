# kinsn -> kfunc companion metadata 重构方案

日期: 2026-03-25

## 目标

在不改变现有 `kinsn` 调用 ABI 和证明语义的前提下，删除当前 verifier 中
`FUNC name -> "<name>_desc" -> kallsyms` 的隐式查找路径，把
`func_id -> kinsn descriptor` 变成显式 companion metadata。

保留不变的部分:
- `BPF_PSEUDO_KINSN_CALL`
- sidecar payload
- proof lowering / restore
- x86/arm64 native emit

替换的部分:
- `fetch_kinsn_desc_meta()` 中的 `_desc` 命名约定
- `kallsyms_lookup_name("<func>_desc")`
- `find_kfunc_desc_module()` 这种为 `_desc` 查找服务的桥接逻辑

## 当前实现的问题

当前 verifier 在
[kernel/bpf/verifier.c](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/verifier.c)
里这样解析 kinsn:

1. 用 `imm/off` 取得 `BTF_KIND_FUNC`
2. 拿到函数名，例如 `bpf_rotate64`
3. 拼成 `bpf_rotate64_desc`
4. 通过 `kallsyms` 或 module kallsyms 查这个符号
5. 把结果解释成 `const struct bpf_kinsn *`

问题:
- `func_id -> desc` 关联是隐式命名约定，不是显式元数据
- verifier 依赖 `kallsyms` 做语义元数据查找，像 POC
- 对符号可见性、重命名、LTO 都更脆
- upstream 很容易质疑“为什么不是显式注册关系”

## 目标设计

### 核心思路

把 `kinsn` descriptor 挂到现有 kfunc companion metadata 上。

不是把 `kinsn` 变成普通 kfunc 语义，而是：
- 复用 `func_id/off -> BTF/module lifetime` 体系
- 复用“按 `func_id/off` 显式取 metadata”这层
- 不复用普通 kfunc 的 call ABI 检查

### 目标数据结构

当前:

```c
struct bpf_kfunc_desc {
	struct btf_func_model func_model;
	u32 func_id;
	s32 imm;
	u16 offset;
	unsigned long addr;
};
```

建议扩成:

```c
struct bpf_kfunc_inline_ops {
	const struct bpf_kinsn *kinsn;
};

struct bpf_kfunc_desc {
	struct btf_func_model func_model;
	u32 func_id;
	s32 imm;
	u16 offset;
	unsigned long addr;
	const struct bpf_kfunc_inline_ops *inline_ops; /* optional */
};
```

或者更直接:

```c
struct bpf_kfunc_desc {
	...
	const struct bpf_kinsn *kinsn; /* optional */
};
```

推荐后一种，代码最少。

## 模块侧改动

### 当前模块侧

模块现在有两类导出物:
- BTF `FUNC` stub，例如 `__bpf_kfunc void bpf_rotate64(void) {}`
- 全局 descriptor，例如 `const struct bpf_kinsn bpf_rotate64_desc = {...}`

但两者的关系只靠名字约定。

### 目标模块侧

需要把这种关系改成显式 companion metadata，例如:

```c
struct bpf_kinsn_kfunc_pair {
	const char *name;
	const struct bpf_kinsn *desc;
};

static const struct bpf_kinsn_kfunc_pair bpf_rotate_pairs[] = {
	{ "bpf_rotate64", &bpf_rotate64_desc },
};
```

更进一步，若直接按 BTF ID set 注册，则可以避免名字字符串:

```c
BTF_KFUNCS_START(bpf_rotate_set)
BTF_ID_FLAGS(func, bpf_rotate64)
BTF_KFUNCS_END(bpf_rotate_set)

static const struct bpf_kinsn *bpf_rotate_descs[] = {
	[0] = &bpf_rotate64_desc,
};
```

模块 init 时调用一个新的 companion 注册接口，把:
- `btf_id_set`
- 对应的 `const struct bpf_kinsn *` 数组

一起注册给核心。

## 内核侧接口

### 新 companion 注册接口

在 `include/linux/bpf.h` / `kernel/bpf/verifier.c` 新增:

```c
struct bpf_kfunc_companion_ops {
	const struct bpf_kinsn *const *kinsn_descs;
	u32 nr_descs;
};

int register_bpf_kfunc_companion_set(struct btf *btf,
				     const struct btf_id_set8 *set,
				     const struct bpf_kfunc_companion_ops *ops,
				     struct module *owner);
void unregister_bpf_kfunc_companion_set(...);
```

这里不需要重新造一套 kinsn registry。
目标是把 companion 信息和现有 kfunc id_set 绑定。

### 查找接口

新增一个通用 helper:

```c
static const struct bpf_kinsn *
btf_kfunc_kinsn_desc(struct btf *btf, u32 func_id, struct bpf_prog *prog);
```

语义:
- 输入 `btf + func_id + prog`
- 输出这个 kfunc 是否带 `kinsn` companion descriptor

## verifier 改动

### 现状

当前 kinsn lookup 路径:
- `add_kinsn_call()`
- `fetch_kinsn_desc_meta()`
- `find_kfunc_desc_module()`
- `find_kallsyms_symbol_value("<name>_desc")`
- `kinsn_tab`

### 目标

改成:
- `add_kinsn_call()` 仍保留
- 但 `fetch_kinsn_desc_meta()` 简化成:
  - `btf = find_kfunc_desc_btf(env, offset)`
  - 验证 `func_id` 是 `BTF_KIND_FUNC`
  - `kinsn = btf_kfunc_kinsn_desc(btf, func_id, env->prog)`
- 不再拼 `_desc`
- 不再查 `kallsyms`
- 不再需要 `find_kfunc_desc_module()`

### 更进一步的收敛

如果 companion metadata 直接挂到 `bpf_kfunc_desc`:
- `add_kfunc_call()` 可在创建 `bpf_kfunc_desc` 时顺手填 `desc->kinsn`
- `add_kinsn_call()` 可进一步简化成“为 kinsn 视图做一个轻量缓存”
- 后续 `bpf_jit_find_kinsn_desc()` 可以从统一表里查

第一阶段不建议硬并 `kfunc_tab` 和 `kinsn_tab`，先把 lookup 显式化即可。

## JIT 改动

JIT 基本不用改语义。

继续保留:
- x86 `emit_kinsn_desc_call()`
- arm64 `emit_kinsn_desc_call_arm64()`

变化只在 descriptor 来源:
- 现在 `bpf_jit_get_kinsn_payload()` 最终依赖 `kinsn_tab`
- companion metadata 方案下，仍可保留 `kinsn_tab` 作为轻量缓存
- 或后续合并成统一 call desc 表

所以 JIT 侧第一阶段几乎不需要变。

## 分阶段实施

### Phase 1: companion metadata 引入，不改 call ABI

改动:
- 模块侧新增显式 `func_id -> desc` companion 注册
- verifier 新增 `btf_kfunc_kinsn_desc()`
- `fetch_kinsn_desc_meta()` 改成显式查 companion metadata
- 删除 `_desc` 命名约定和 `kallsyms` 查找

保留:
- `PSEUDO_KINSN_CALL`
- `kinsn_tab`
- proof lowering / restore

收益:
- 去掉最 hack 的 lookup 路径
- upstream 叙事显著更好

### Phase 2: 并表

改动:
- 给 `bpf_kfunc_desc` 直接挂 `const struct bpf_kinsn *`
- 让 `bpf_jit_find_kinsn_desc()` 从统一表查
- 删除独立 `kinsn_tab`
- 删除 `find_kinsn_desc()` / `kinsn_desc_cmp_by_imm_off()` / 一部分 `add_kinsn_call()` 重复逻辑

收益:
- 继续去重 verifier plumbing

### Phase 3: 若要继续上游化

再讨论是否:
- 把 `PSEUDO_KINSN_CALL` 变成 `PSEUDO_KFUNC_CALL + special flag`
- 或保留现状但只统一 metadata 层

这不是当前第一步必需。

## 预估代码量变化

### 仅做 Phase 1

净变化预估:
- `kernel/bpf/verifier.c`: `-50 ~ -110`
- `module/*`: `+40 ~ +90`
- `include/linux/bpf.h` / companion 声明: `+20 ~ +40`

总计:
- `vendor/linux-framework`: `-30 ~ -80` 行净变化
- 如果算 module 仓内文件，总体大约 `-10 ~ -60`

原因:
- verifier 会明显变短
- 但模块侧要补显式 companion metadata/注册代码

### 做到 Phase 2

净变化预估:
- `kernel/bpf/verifier.c`: 再减 `-60 ~ -120`
- `include/linux/bpf.h`: `+5 ~ +15`
- module 侧变化很小

总计:
- 相对当前树，累计大约 `-90 ~ -180` 行

### 为什么不会少几百行

因为大头不在 lookup hack，而在这些无法消掉的块:
- `lower_kinsn_proof_regions()`
- `restore_kinsn_proof_regions()`
- `build_kinsn_inst_seq()`
- `do_check_insn()` / `do_misc_fixups()` / `bpf_check()` 的接入点

这些是 `kinsn` 语义本体，不是 registry/lookup 重复。

## 风险

主要风险:
- companion metadata 和现有 kfunc id_set 绑定方式需要设计清楚
- 不能引入新的平行 registry，否则只是把 `_desc` hack 换成另一套私有表
- 若第一阶段过度追求并表，容易把风险扩到普通 kfunc 路径

因此建议:
- 先做 Phase 1，只替换 lookup
- 测试稳定后再做 Phase 2 并表

## 推荐结论

如果目标是“更像 upstream 会接受，同时尽量少动”：

最佳下一步是:
- 做 Phase 1
- 不改 `PSEUDO_KINSN_CALL`
- 不碰 proof lowering
- 只把 `func_id -> desc` 从 `_desc + kallsyms` 改成显式 companion metadata

这一步不是最大幅度减代码，但它能把当前最像 POC 的一块换掉。

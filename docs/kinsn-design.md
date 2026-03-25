# kinsn v2 设计与实现

日期：2026-03-24  
状态：current design + current implementation  
主题：first-class kinsn IR + proof lowering + pure kinsn transport

## 0. 文档定位

本文档描述当前仓库里的 `kinsn` 正式设计和实际实现。

它以这三类信息为准：

- 长期目标与抽象边界：
  - [docs/tmp/20260323/kinsn_v2_instantiate_design_20260323.md](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260323/kinsn_v2_instantiate_design_20260323.md)
- 当前 kernel 实现：
  - [vendor/linux-framework/include/linux/bpf.h](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/include/linux/bpf.h)
  - [vendor/linux-framework/include/linux/btf.h](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/include/linux/btf.h)
  - [vendor/linux-framework/include/linux/bpf_verifier.h](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/include/linux/bpf_verifier.h)
  - [vendor/linux-framework/kernel/bpf/verifier.c](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/verifier.c)
  - [vendor/linux-framework/kernel/bpf/btf.c](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/btf.c)
  - [vendor/linux-framework/arch/x86/net/bpf_jit_comp.c](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/x86/net/bpf_jit_comp.c)
  - [vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c)
- 当前 module / daemon / tests：
  - [module/include/kinsn_common.h](/home/yunwei37/workspace/bpf-benchmark/module/include/kinsn_common.h)
  - [module/x86/bpf_rotate.c](/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_rotate.c)
  - [module/x86/bpf_extract.c](/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_extract.c)
  - [module/x86/bpf_select.c](/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_select.c)
  - [module/x86/bpf_endian.c](/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_endian.c)
  - [module/x86/bpf_barrier.c](/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_barrier.c)
  - [daemon/src/insn.rs](/home/yunwei37/workspace/bpf-benchmark/daemon/src/insn.rs)
  - [daemon/src/kfunc_discovery.rs](/home/yunwei37/workspace/bpf-benchmark/daemon/src/kfunc_discovery.rs)
  - [daemon/src/passes/utils.rs](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/utils.rs)
  - [tests/unittest/rejit_kinsn.c](/home/yunwei37/workspace/bpf-benchmark/tests/unittest/rejit_kinsn.c)

本文档已经不再把 `kinsn` 描述成 v1 的 “is-a kfunc + effect DSL”。  
当前仓库的主线设计是 pure v2。

## 1. 一句话定义

`kinsn` 是一等扩展指令。

它的核心语义是：

- 原始程序里保留 first-class `kinsn`
- `instantiate_insn(payload, insn_buf)` 定义它的 canonical BPF-visible semantics
- verifier 通过 proof lowering 证明它
- native JIT 直接对原始 `kinsn` 发射机器码
- generic fallback 在需要时回到同一份 instantiated BPF 序列

也就是说：

- `kinsn` 不是 kfunc
- 普通 BPF 是它的 proof object / fallback object
- 不是它的长期身份

## 2. 当前 v2 的核心边界

### 2.1 first-class IR

当前实现已经把 `kinsn` 视为 first-class instruction：

- 有独立的 `BPF_PSEUDO_KINSN_CALL`
- 有独立的 sidecar tag `BPF_PSEUDO_KINSN_SIDECAR`
- verifier 有独立的 `kinsn_tab`
- JIT 有独立的 kinsn dispatch
- module 导出的是 `struct bpf_kinsn` descriptor，不是 `bpf_kinsn_ops`

对应代码：

- [vendor/linux-framework/include/uapi/linux/bpf.h](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/include/uapi/linux/bpf.h)
- [vendor/linux-framework/include/linux/bpf.h](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/include/linux/bpf.h)

### 2.2 `instantiate_insn()` 是唯一 canonical 语义源

当前 descriptor 形状是：

```c
struct bpf_kinsn {
	struct module *owner;
	u16 max_insn_cnt;
	u16 max_emit_bytes;

	int (*instantiate_insn)(u64 payload, struct bpf_insn *insn_buf);

	int (*emit_x86)(u8 *image, u32 *off, bool emit,
			u64 payload, const struct bpf_prog *prog);
	int (*emit_arm64)(u32 *image, int *idx, bool emit,
			  u64 payload, const struct bpf_prog *prog);
};
```

见 [vendor/linux-framework/include/linux/bpf.h](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/include/linux/bpf.h)。

这意味着：

- verifier 不再消费 `model_call()` / `bpf_kinsn_effect`
- module 直接提供 canonical instantiated BPF
- native emit 是对这份语义的 refinement，不是另一套 verifier 语义来源

### 2.3 proof lowering，而不是 effect DSL

当前 verifier 的主线是：

1. 识别 `sidecar + BPF_PSEUDO_KINSN_CALL`
2. 解析 target descriptor
3. 调 `instantiate_insn(payload, env->insn_buf)`
4. 验证 proof sequence 合法
5. 在 verifier 主分析阶段临时 lower 成普通 BPF
6. 主分析结束后 restore 回原始 `kinsn`

对应代码：

- [vendor/linux-framework/kernel/bpf/verifier.c](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/verifier.c)
  - `validate_kinsn_proof_seq()`
  - `build_kinsn_inst_seq()`
  - `lower_kinsn_proof_regions()`
  - `restore_kinsn_proof_regions()`

## 3. transport：当前已经是 pure kinsn transport

### 3.1 指令编码

当前 transport 是：

- 一条 sidecar pseudo-insn 承载 payload
- 一条专用 `CALL`，`src_reg = BPF_PSEUDO_KINSN_CALL`

不是：

- `PSEUDO_KFUNC_CALL`
- kfunc FUNC id
- `KF_KINSN`

daemon 当前发射的是：

- [sidecar](/home/yunwei37/workspace/bpf-benchmark/daemon/src/insn.rs)
- [kinsn_call](/home/yunwei37/workspace/bpf-benchmark/daemon/src/insn.rs)

### 3.2 当前 payload 载体

sidecar payload 仍然使用一条 `MOV K` 指令的剩余位承载：

- 低 4 bit：`dst_reg`
- 中间 16 bit：`off`
- 高 32 bit：`imm`

kernel 打包接口见：

- [vendor/linux-framework/include/linux/bpf.h](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/include/linux/bpf.h)
  - `bpf_kinsn_sidecar_payload()`

daemon 对应编码见：

- [daemon/src/insn.rs](/home/yunwei37/workspace/bpf-benchmark/daemon/src/insn.rs)
  - `BpfInsn::kinsn_sidecar()`

### 3.3 当前 target identity

当前 `CALL.imm` 不是 FUNC id，而是：

- module BTF 里的 `BTF_KIND_VAR` id
- 这个 VAR 的类型必须是 `struct bpf_kinsn`

当前 `CALL.off` 仍然承载：

- module BTF fd slot

也就是说，当前 transport 已经脱离了 `kfunc` 身份，但仍然复用 “module BTF fd_array 命名空间” 这一层来定位外部 module BTF。

这是当前实现中的实际折中点。

### 3.4 descriptor registration

当前 runtime lookup 不再走 `kallsyms_lookup_name()`。

它已经收敛成：

- module init 时调用 `register_bpf_kinsn_set()`
- 把 `{ BTF var name -> const struct bpf_kinsn * }` 解析并写入 `btf->kinsn_tab`
- verifier load 时通过 `(struct btf *, var_id)` lookup descriptor
- JIT 不再重新 lookup，而是直接使用 `prog->aux->kinsn_tab`

对应代码：

- [vendor/linux-framework/kernel/bpf/btf.c](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/btf.c)
  - `register_bpf_kinsn_set()`
  - `unregister_bpf_kinsn_set()`
  - `btf_try_get_kinsn_desc()`
- [module/include/kinsn_common.h](/home/yunwei37/workspace/bpf-benchmark/module/include/kinsn_common.h)
  - `DEFINE_KINSN_V2_MODULE(...)`
- [vendor/linux-framework/kernel/bpf/verifier.c](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/verifier.c)
  - `fetch_kinsn_desc_meta()`

## 4. verifier 里的 proof lowering

### 4.1 时序

当前实现采用的是：

- `add_subprog_and_kfunc()` 之后，先收集 kinsn descriptor
- `check_subprogs()` / `check_cfg()` / `do_check_*()` 之前做 lowering
- `do_check_main()` / `do_check_subprogs()` 之后 restore 回原始 `kinsn`
- restore 发生在 `remove_fastcall_spills_fills()` 之前

这是当前代码中的真实时序，而不是仅仅文档里的设想。

### 4.2 lowering / restore 机制

当前实现就是“验证前展开，验证后 replace”。

具体做法：

- lowering 阶段
  - 保存原始 `sidecar + call`
  - `verifier_remove_insns()` 删除 sidecar
  - `bpf_patch_insn_data()` 把 `call` 位置扩成 instantiated proof sequence
- restore 阶段
  - `bpf_patch_insn_data()` 先把 proof region 开头改回原始两条
  - `verifier_remove_insns()` 删掉剩余 proof 指令

这里没有额外造一个复杂框架。  
当前实现主要复用了现有 patch/rewrite 基础设施，只补了最小的 `kinsn_region` bookkeeping。

### 4.3 proof sequence 约束

当前 verifier 会显式验证 proof sequence 的结构安全性。

关键约束包括：

- 不允许 helper / kfunc / subprog / tailcall
- 不允许跳出 region
- 不允许形成 back-edge
- 要求 sequence 自身是合法 BPF 指令流

这样做的目的不是“替 module 证明优化正确”，而是保证：

- verifier 真正在分析的 proof object 是良构的普通 BPF

### 4.4 restore 后的执行表示

当前 restore 完成后：

- 原始程序里仍然是 `sidecar + kinsn_call`
- verifier 后续 rewrite / JIT 看到的是原始 `kinsn`

这正是当前设计刻意要保留的一点：

- proof object 只是 proof object
- 它不吞掉 first-class `kinsn`

## 5. 执行和 fallback

### 5.1 native JIT

当前 x86 / arm64 都直接对原始 `kinsn` dispatch：

- [vendor/linux-framework/arch/x86/net/bpf_jit_comp.c](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/x86/net/bpf_jit_comp.c)
  - `emit_kinsn_desc_call()`
- [vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c)
  - `emit_kinsn_desc_call_arm64()`

JIT 取 descriptor 的路径是：

- `prog->aux->kinsn_tab`
- `bpf_jit_get_kinsn_payload()`

不是重新去查 BTF symbol 或 `kallsyms`。

### 5.2 generic fallback

当前 generic fallback 不是“回退成 kfunc 语义”，而是：

- 在 `do_misc_fixups()` 阶段
- 如果当前 program 没有可用 native emit
- 就把原始 `kinsn` 站点再 lower 成普通 BPF 指令序列

对应代码：

- [vendor/linux-framework/kernel/bpf/verifier.c](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/verifier.c)
  - `do_misc_fixups()`

这点非常重要，因为当前实现已经满足：

- **JIT 不支持时，fallback 是 instantiated BPF sequence，不是 fallback 回 kfunc**

## 6. module / daemon / tests 的边界

### 6.1 module 的职责

每个 kinsn module 现在负责：

- 导出 `const struct bpf_kinsn ..._desc`
- 提供 `instantiate_insn(payload, ...)`
- 提供目标架构 native emit
- 通过 `DEFINE_KINSN_V2_MODULE(...)` 注册 descriptor set

当前已有的对象包括：

- rotate
- select
- extract
- endian load16/load32/load64
- speculation barrier

### 6.2 daemon 的职责

当前 daemon 已经配合 pure-v2 transport。

它负责：

- 在 module BTF 里找 `BTF_KIND_VAR` descriptor
- 获取其 absolute BTF id
- 发射 `sidecar + BPF_PSEUDO_KINSN_CALL`
- 继续做模式匹配与站点选择

它不负责：

- 语义证明
- native emit
- verifier 模型

### 6.3 tests 的职责

repo-owned 回归测试当前主要在：

- [tests/unittest/rejit_kinsn.c](/home/yunwei37/workspace/bpf-benchmark/tests/unittest/rejit_kinsn.c)

它覆盖的核心点包括：

- packed sidecar 语义
- proof lowering / restore 的结构正确性
- dense program 回归
- specific bug regressions

## 7. 当前实现和 tmp v2 文档的关系

[docs/tmp/20260323/kinsn_v2_instantiate_design_20260323.md](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260323/kinsn_v2_instantiate_design_20260323.md) 是目标设计文档。  
本文档是它在当前仓库中的落地版。

两者当前是一致的核心点：

- `kinsn` 是 first-class IR
- `instantiate_insn()` 是 canonical 语义源
- verifier 使用 proof lowering
- 执行/JIT 保持原始 `kinsn` 为主表示
- transport 已经纯化为 dedicated pseudo kinsn call

两者的差别只在于：

- tmp 文档更偏 “目标边界 / 设计原则”
- 本文档更偏 “当前代码到底已经实现到哪一步”

## 8. 当前已知 open issues

### 8.1 proof lowering 的规模问题仍然存在

当前 proof lowering 仍然是：

- 按 site 在 live verifier program 上做 patch/restore

所以它仍然有一个结构性 open issue：

- 复杂度更接近 `O(site_count * prog_len)`
- 继续受现有 patch/rewrite machinery 约束

这不是当前 correctness blocker，但仍然是长期最主要的 open issue。

### 8.2 commit / upstream cleanliness 仍要继续收敛

当前代码虽然语义已经是 pure-v2，但 patch series 视角上仍有需要继续整理的地方：

- prep refactor 与 feature patch 还要更干净地拆开
- 一些非核心 churn 还要继续压缩

这属于 patch-series 组织问题，不属于当前 `kinsn` 语义模型的问题。

## 9. 结论

当前仓库里的 `kinsn` 已经不是 v1。

它现在的真实设计是：

- first-class `kinsn`
- dedicated `PSEUDO_KINSN_CALL`
- per-BTF descriptor registration
- verifier proof lowering + restore
- native JIT 直接发原始 `kinsn`
- JIT 不支持时 fallback 成 instantiated BPF sequence

因此，后续讨论、修改和 reviewer 交流，都应以这个模型为准，而不再以旧的：

- `kfunc + effect DSL`
- `model_call()`
- `bpf_kinsn_effect`

为准。

# kinsn vs kfunc：本质差异与 novelty 论证

日期：2026-03-28  
目标：回应 reviewer 的质疑

> “如果 kinsn 本质上就是 kfunc + KF_INLINE_EMIT + emit callback，那第 3 节把它包装成独立 bytecode abstraction / extended ISA 就显得过度陈述。kinsn 相对已有 kfunc，到底多了什么不可替代的新能力？”

## 0. 先给结论

基于当前代码树，`kinsn` 不能被准确描述成“普通 kfunc 加一个 inline emit 回调”。  
它和普通 `kfunc` 的本质差异在于：

1. **语义源不同**：普通 `kfunc` 的 verifier 语义来自“BTF 原型 + flags”，函数体是黑盒；`kinsn` 的 verifier 语义来自 `instantiate_insn()` 生成的 ordinary-BPF proof sequence，verifier 真正逐条验证这段 proof sequence，而不是把它当黑盒 call。  
   代码证据：`vendor/linux-framework/include/linux/bpf.h:968-979`，`vendor/linux-framework/kernel/bpf/verifier.c:3669-3835`，`vendor/linux-framework/kernel/bpf/verifier.c:26408-26484`。

2. **抽象层级不同**：普通 `kfunc` 仍然是“函数调用”；`kinsn` 是“指令形式”的 transport。daemon 发出的不是 `BPF_PSEUDO_KFUNC_CALL`，而是“`sidecar + BPF_PSEUDO_KINSN_CALL`”这一对专用 bytecode 形式，payload 直接携带结果寄存器、输入寄存器、offset 等操作数字段。  
   代码证据：`daemon/src/insn.rs:243-290`，`vendor/linux-framework/include/linux/bpf.h:996-1007`，`vendor/linux-framework/kernel/bpf/verifier.c:21355-21476`。

3. **执行路径不同**：普通 `kfunc` 在 JIT 里被解析为真正的 runtime function call；`kinsn` 在 JIT 里根本不走函数地址调用，而是直接根据 descriptor + payload 发 native code。  
   代码证据：普通 `kfunc` 路径 `vendor/linux-framework/kernel/bpf/verifier.c:3542-3566` 与 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2477-2499`；`kinsn` 路径 `vendor/linux-framework/kernel/bpf/verifier.c:3524-3541`、`vendor/linux-framework/kernel/bpf/verifier.c:3882-3910`、`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:579-606`、`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2477-2483`。

4. **降级路径不同**：普通 `kfunc` 缺失时，调用点不可成立；BpfReJIT 的 `kinsn` pass 在 module/BTF 不可发现时直接不改写原程序，程序照常跑原始 eBPF；即便改写后缺少 native emit，kernel 也能回退到 proof sequence。  
   代码证据：`daemon/src/kfunc_discovery.rs:352-381`，`daemon/src/passes/rotate.rs:29-56`，`daemon/src/passes/cond_select.rs:143-171`，`vendor/linux-framework/kernel/bpf/verifier.c:23755-23795`。

因此，**复用 kfunc 注册/发现基础设施，只是 plumbing reuse；并不把 kinsn 降格成“普通 kfunc 的语义子集”**。  
真正独立存在的是三件东西：`sidecar` transport、proof-lowering verifier path、native emit dispatch。

---

## 1. 一个必须先纠正的前提：当前树里没有 `bpf_kinsn_effect / model_call`

题目背景里提到的 `bpf_kinsn_ops` / `bpf_kinsn_effect` / `model_call()`，**不是当前 in-tree 实现**。

当前 `include/linux/bpf.h` 里真正存在的是：

```c
struct bpf_kinsn {
	struct module *owner;
	u16 max_insn_cnt;
	u16 max_emit_bytes;
	int (*instantiate_insn)(u64 payload, struct bpf_insn *insn_buf);
	int (*emit_x86)(u8 *image, u32 *off, bool emit, u64 payload, const struct bpf_prog *prog);
	int (*emit_arm64)(u32 *image, int *idx, bool emit, u64 payload, const struct bpf_prog *prog);
};
```

代码证据：`vendor/linux-framework/include/linux/bpf.h:968-979`。  
设计文档也明确写了：**“There is no active `model_call()` or `bpf_kinsn_effect` path in the current tree.”**  
证据：`docs/kinsn-design.md:103-109`。

这意味着：

- 当前 tree 中，`kinsn` 的 verifier 语义不是 declarative effect DSL。
- 当前 tree 中，`kinsn` 的 verifier 语义来源是 `instantiate_insn()` 生成的 ordinary-BPF proof sequence。
- 因此，下面的 novelty 论证必须以 **proof-lowering model** 为准，而不能再按旧版 effect DSL 叙述。

这点很重要，因为 reviewer 如果按当前代码审读，你在正文里继续强调 `bpf_kinsn_effect`，会立刻被抓住“实现与论证不一致”。

---

## 2. 一张总表：普通 kfunc 与当前 kinsn 的真正差异

| 维度 | 普通 kfunc | 当前 kinsn |
| --- | --- | --- |
| 注册入口 | `register_btf_kfunc_id_set()` | 也复用 `register_btf_kfunc_id_set()`，但额外挂接 `kinsn_descs` |
| bytecode 编码 | `BPF_PSEUDO_KFUNC_CALL` | `sidecar + BPF_PSEUDO_KINSN_CALL` |
| verifier 看到什么 | call 指令；按 BTF prototype / flags 做参数与返回值建模 | 先被 lower 成 ordinary-BPF proof sequence，再跑标准 verifier |
| 语义源 | BTF 原型 + flags；函数体黑盒 | `instantiate_insn()` 生成的 proof sequence |
| JIT 执行 | 真实 `call` 到 kernel function 地址 | 直接 `emit_x86/emit_arm64` 内联发码 |
| 是否需要函数地址 | 需要：`kallsyms_lookup_name()` | 不需要：只需要 descriptor + payload |
| 操作数传递 | 走 R1-R5 调用 ABI，返回值在 R0 | payload 里直接携带 dst/src/off 等字段 |
| module 缺失时 | 调用点不可成立 | daemon 直接不改写原程序；已改写但无 native emit 时还能回退 proof sequence |
| 是否仍是“函数调用”抽象 | 是 | 否，已经是专用 instruction form |

对应代码：

- 复用注册入口但额外挂接 `kinsn_descs`：`vendor/linux-framework/include/linux/btf.h:122-127`，`vendor/linux-framework/kernel/bpf/btf.c:8784-8816`。
- 普通 `kfunc` 查到的是 `addr + func_model`：`vendor/linux-framework/kernel/bpf/verifier.c:3542-3566`。
- `kinsn` 查到的是 `desc->kinsn` 而不是函数地址：`vendor/linux-framework/kernel/bpf/verifier.c:3524-3541`。
- 普通 call bytecode 与 kinsn bytecode 区分：`daemon/src/insn.rs:223-255`。
- sidecar payload 编码：`daemon/src/insn.rs:277-290`，`vendor/linux-framework/include/linux/bpf.h:996-1007`。

---

## 3. “用 kfunc infra 实现”只是 plumbing reuse，不是语义等价

### 3.1 共享的是注册表，不是 verifier/JIT 语义

`kinsn` 的确复用了 kfunc 注册基础设施：

- `struct btf_kfunc_id_set` 多了 `const struct bpf_kinsn * const *kinsn_descs;`  
  证据：`vendor/linux-framework/include/linux/btf.h:122-127`
- 注册时，`btf_populate_kfunc_set()` 把 `(btf_id -> kinsn desc)` 填入独立的 `kinsn_sets`  
  证据：`vendor/linux-framework/kernel/bpf/btf.c:8784-8816`
- 查询时，`btf_kfunc_kinsn_desc()` 从这个附加表里取 descriptor  
  证据：`vendor/linux-framework/kernel/bpf/btf.c:8987-9005`

但是从 verifier 开始，普通 `kfunc` 与 `kinsn` 立即分叉：

- 普通 `kfunc` 分支：查 symbol 地址、蒸馏 `btf_func_model`、最终发出 runtime call  
  证据：`vendor/linux-framework/kernel/bpf/verifier.c:3542-3566`
- `kinsn` 分支：要求 `instantiate_insn != NULL`，保存 `desc->kinsn`，完全不取函数地址  
  证据：`vendor/linux-framework/kernel/bpf/verifier.c:3524-3541`

因此，**“用 kfunc infra 实现”只能推出 registration path 被复用，不能推出 semantic abstraction 没有新东西**。

### 3.2 如果将来统一到 kfunc 路径，也不等于 kinsn 不需要独立存在

即使把 `PSEUDO_KINSN_CALL` 统一编码到 `PSEUDO_KFUNC_CALL`，只要下面三样还在，`kinsn` 仍是独立抽象：

1. sidecar payload transport
2. proof-lowering verifier path
3. native emit dispatch

换句话说，**可以统一 plumbing，但不能消掉 abstraction**。  
消掉这三样之后，剩下的才只是“普通 kfunc 调用”。

---

## 4. verifier 本质差异：普通 kfunc 是黑盒 call，kinsn 是 proof-visible instruction

## 4.1 普通 kfunc：verifier 不看函数体，只看原型/flags

普通 `kfunc` 的元数据来自：

- BTF function prototype
- kfunc flags
- 允许性检查

证据：

- `fetch_kfunc_meta()` 从 BTF 取 `func_proto`、`func_name`、`kfunc_flags`：`vendor/linux-framework/kernel/bpf/verifier.c:3405-3449`
- `fetch_kfunc_arg_meta()` 只把 `btf/proto/name/flags` 填入 `meta`：`vendor/linux-framework/kernel/bpf/verifier.c:14203-14226`
- `check_kfunc_args()` 逐个参数按 BTF 类型做检查：`vendor/linux-framework/kernel/bpf/verifier.c:13656-14120`
- 返回值按 BTF 返回类型建模：`vendor/linux-framework/kernel/bpf/verifier.c:14650-14779`
- 调用后统一 clobber caller-saved regs：`vendor/linux-framework/kernel/bpf/verifier.c:14643-14648`

普通 `kfunc` descriptor 里保存的是：

```c
struct bpf_kfunc_desc {
	struct btf_func_model func_model;
	const struct bpf_kinsn *kinsn;
	u32 func_id;
	s32 imm;
	u16 offset;
	unsigned long addr;
};
```

证据：`vendor/linux-framework/kernel/bpf/verifier.c:3180-3187`。

对普通 `kfunc`，最终被填充的是 `addr` 和 `func_model`，而不是 `kinsn`：

- `addr = kallsyms_lookup_name(kfunc.name)`  
- `btf_distill_func_proto(..., &func_model)`  
- `desc->addr = addr; desc->func_model = func_model;`

证据：`vendor/linux-framework/kernel/bpf/verifier.c:3542-3566`，`vendor/linux-framework/kernel/bpf/btf.c:7485-7553`。

这说明普通 `kfunc` 的 verifier 视角始终是：“这是一个黑盒函数调用；我只知道签名，不知道函数体。”

## 4.2 kinsn：verifier 真正验证的是 instantiated proof sequence

`kinsn` 走的是完全不同的路径：

1. `add_subprog_and_kfunc()` 识别 `BPF_PSEUDO_KINSN_CALL`，统计 `env->kinsn_call_cnt`，并以 `kinsn_call=true` 注册 descriptor。  
   证据：`vendor/linux-framework/kernel/bpf/verifier.c:3928-3963`

2. `lower_kinsn_proof_regions()` 在主 verifier 之前，把每个 `sidecar + kinsn_call` 替换成 `instantiate_insn(payload)` 生成的 proof sequence。  
   证据：`vendor/linux-framework/kernel/bpf/verifier.c:3723-3835`

3. verifier 随后对 lowered 程序跑标准流程：`check_subprogs()`、`check_cfg()`、`compute_postorder()`、`compute_scc()`、`compute_live_registers()`、`do_check_main()`、`do_check_subprogs()`。  
   证据：`vendor/linux-framework/kernel/bpf/verifier.c:26408-26484`

4. 验证成功后，再 `restore_kinsn_proof_regions()` 把 proof sequence 恢复回原始 sidecar+call transport。  
   证据：`vendor/linux-framework/kernel/bpf/verifier.c:3837-3879`，`vendor/linux-framework/kernel/bpf/verifier.c:26479-26484`

还要注意两条非常强的证据：

- verifier 明确禁止“未 lowering 的 kinsn call”继续走普通 call 检查：  
  `internal error: kinsn call reached verifier without proof lowering`  
  证据：`vendor/linux-framework/kernel/bpf/verifier.c:21474-21476`

- `check_kinsn_sidecar_insn()` 只做 transport 完整性检查，要求 sidecar 后面必须立刻跟 kinsn call。  
  证据：`vendor/linux-framework/kernel/bpf/verifier.c:21355-21372`

所以，**当前 tree 中 kinsn 的 verifier 语义来源不是 call rule，而是 proof-lowering 后的 ordinary BPF**。  
这已经足以把它和普通 `kfunc` 区分开。

## 4.3 这比“普通 kfunc + emit callback”多了什么？

多出来的是：**call 站点不再被 verifier 当作 opaque function invocation，而被当作一个可以展开、验证、恢复的 instruction-form object。**

这正是 reviewer 质疑中的关键误区。  
如果只是“普通 kfunc + emit callback”，verifier 侧仍然会停留在 `check_kfunc_call()` 这条黑盒语义路径上。  
当前 `kinsn` 不是这样；它有一整条独立的 proof-lowering verifier path。

## 4.4 需要诚实加上的一个 caveat

如果按你最初的 `bpf_kinsn_effect` 说法，结论会更强：module 只能声明 effect，core verifier 强制执行 effect。  
**但这不是当前 tree 的实现。**

当前 tree 的真实安全叙述应更精确地写成：

- **BPF-visible safety** 来自 ordinary-BPF proof sequence 的标准 verifier；
- **native correctness** 额外依赖 `emit_x86/emit_arm64` 对 `instantiate_insn()` 的 refinement。

也就是说，当前 tree 确实比普通 `kfunc` 更“可验证”，但它的 novelty 是 **proof-visible instruction semantics**，不是更强的 **effect-DSL trust narrowing**。

---

## 5. 抽象层级差异：函数调用 vs 指令形式

## 5.1 普通 kfunc 仍然是 call ABI

普通 BPF call 的 helper/kfunc 原型是固定走寄存器 ABI 的：`func(u64 r1, u64 r2, u64 r3, u64 r4, u64 r5)`。  
证据：`vendor/linux-framework/include/linux/bpf.h:924-965`。

如果把一个局部 peephole 重写成普通 `kfunc`，即便语义上可行，也仍然要承担：

- 参数搬运到 R1-R5
- runtime `call` / `ret`
- 返回值从 R0 再搬回目标寄存器
- caller-saved clobber 语义

这仍然是**函数级**抽象。

## 5.2 kinsn transport 是专用 instruction form

daemon 发出的 kinsn 不是普通 call，而是：

1. `BpfInsn::kinsn_sidecar(payload)`
2. `BpfInsn::call_kinsn_with_off(btf_id, off)`

证据：`daemon/src/passes/utils.rs:281-292`，`daemon/src/insn.rs:243-290`。

payload 直接编码：

- 结果寄存器
- 输入寄存器
- offset
- 立即数参数

因此，**operand/result placement 是 payload-level，而不是 ABI-level**。

`emit_packed_kinsn_call_with_off()` 的注释甚至明确写了：

> “The result register is part of `payload`, so no extra `mov dst, r0` is emitted here.”

证据：`daemon/src/passes/utils.rs:281-292`。

这就是为什么它是 instruction abstraction，而不是 function abstraction。

## 5.3 具体 pass 里，替换粒度就是 instruction-form 粒度

### rotate

- 识别的是 `MOV provenance + RSH + LSH + OR` 窗口  
  证据：`daemon/src/passes/rotate.rs:239-360`
- `old_len = (pc + 3) - mov_pc`，即典型 4→2 BPF transport 替换  
  证据：`daemon/src/passes/rotate.rs:294-309`
- native emit 不是函数调用，而是 x86 `mov + rol` 或 ARM64 `EXTR`  
  证据：`module/x86/bpf_rotate.c:95-125`，`module/arm64/bpf_rotate.c:68-95`

### cond_select

- 识别 4-insn diamond 或 3-insn short pattern  
  证据：`daemon/src/passes/cond_select.rs:327-411`
- `old_len` 分别为 4 或 3  
  证据：`daemon/src/passes/cond_select.rs:361`，`daemon/src/passes/cond_select.rs:411`
- native emit 是 x86 `test + cmov` 或 ARM64 `tst + csel`  
  证据：`module/x86/bpf_select.c:102-146`，`module/arm64/bpf_select.c:71-105`

### extract

- 识别 `RSH + AND` 两条指令  
  证据：`daemon/src/passes/extract.rs:55-94`
- `old_len = 2`，替换成 2-insn transport  
  证据：`daemon/src/passes/extract.rs:77-83`，`daemon/src/passes/extract.rs:196-200`
- native emit 是直接内联 bitfield extract sequence，而不是 helper body call  
  证据：`module/x86/bpf_extract.c:96-127`，`module/arm64/bpf_extract.c:64-90`

### endian_fusion

- 识别 `LDX_MEM + ENDIAN_TO_BE`  
  证据：`daemon/src/passes/endian.rs:17-33`，`daemon/src/passes/endian.rs:53-107`
- 直接把 offset 编进 payload；必要时也只是在 packed transport 周围补地址物化，而不是切回 legacy call ABI  
  证据：`daemon/src/passes/endian.rs:155-210`
- 注释明确说“instead of using any legacy call ABI”  
  证据：`daemon/src/passes/endian.rs:30-33`

### bulk_memory

- 识别大段 scalarized memcpy/memset  
  证据：`daemon/src/passes/bulk_memory.rs:92-93`
- `MIN_BULK_BYTES = 32`，`CHUNK_MAX_BYTES = 128`  
  证据：`daemon/src/passes/bulk_memory.rs:12-18`
- 每个 chunk 仅发出 `2` 条 transport 指令  
  证据：`daemon/src/passes/bulk_memory.rs:529-547`，`daemon/src/passes/bulk_memory.rs:557-573`
- verifier proof sequence 却可以展开为最多 `128*2` 条 bytewise memcpy 指令  
  证据：`module/x86/bpf_bulk_memory.c:131-150`，`module/x86/bpf_bulk_memory.c:449-455`

这类“**大窗口 -> 单个逻辑指令 -> 小 native 序列**”的替换，正是普通 `kfunc` 难以等价替代的地方。

---

## 6. 优雅降级：这也是普通 kfunc 不具备的产品级属性

## 6.1 module 没加载时，daemon 直接保持原始 bytecode

discovery 阶段如果 `/sys/kernel/btf/<module>` 不存在，就把该 target 标成 unavailable：

- `module '<name>' not loaded (no BTF at ...)`
- 对应 `registry.*_btf_id` 保持 `-1`

证据：`daemon/src/kfunc_discovery.rs:311-381`。

各 pass 在发现 target 不可用时，直接 `changed=false` 返回，不改原程序：

- rotate：`daemon/src/passes/rotate.rs:29-41`
- cond_select：`daemon/src/passes/cond_select.rs:143-171`
- extract：`daemon/src/passes/extract.rs:111-138`
- endian_fusion：`daemon/src/passes/endian.rs:228-266`
- bulk_memory：`daemon/src/passes/bulk_memory.rs:151-175`

这意味着 **module 缺失不会导致应用程序不能运行，只会让优化 pass 不生效**。

## 6.2 module 存在但当前架构/后端没有 native emit 时，kernel 回退到 proof sequence

在 `do_misc_fixups()` 里：

- 若 `prog->jit_requested && bpf_kinsn_has_native_emit(kinsn)`，保留 sidecar+call 给 JIT 原生发码；
- 否则，就把 sidecar+call 替换成 `instantiate_insn()` 生成的 proof sequence。

证据：`vendor/linux-framework/kernel/bpf/verifier.c:23755-23795`。

所以 kinsn 有两层 graceful degradation：

1. **用户态 pass 层**：没发现 module，就不改写
2. **内核 JIT 层**：发现了 kinsn 但没 native emit，也还能退回 ordinary BPF

这比“硬依赖某个 kfunc 必须存在，否则 load fail”更平滑。

---

## 7. “纯用 kfunc 能不能做出同样效果？”答案是：不能等价复制当前实现的关键性质

## 7.1 代码已经表明这些 pass 依赖的是 packed kinsn，而不是普通 kfunc

当前真正使用 `emit_packed_kinsn_call_with_off()` 的 pass 一共有 5 个：

1. `bulk_memory`
2. `rotate`
3. `cond_select`
4. `extract`
5. `endian_fusion`

证据：

- `daemon/src/passes/bulk_memory.rs`
- `daemon/src/passes/rotate.rs`
- `daemon/src/passes/cond_select.rs`
- `daemon/src/passes/extract.rs`
- `daemon/src/passes/endian.rs`

这些 pass 发出的都是 `BPF_PSEUDO_KINSN_CALL`，不是 `BPF_PSEUDO_KFUNC_CALL`。  
证据：`daemon/src/passes/utils.rs:281-292`，以及各 pass 的 replacement 构造代码。

## 7.2 某些 pass 明确拒绝回退到 legacy call ABI

最清楚的是 `endian_fusion` 和 `cond_select`：

- `endian_fusion` 注释明确说，即便 offset 不能直接编码，也是在 packed transport 周围补地址计算，**“instead of using any legacy call ABI”**。  
  证据：`daemon/src/passes/endian.rs:30-33`

- `cond_select` 如果 true/false 不是寄存器值，就直接 skip，原因是 packed path 需要 register operands；它没有实现任何“普通 kfunc ABI fallback”。  
  证据：`daemon/src/passes/cond_select.rs:104-111`，`daemon/src/passes/cond_select.rs:227-233`

这不是偶然，而是实现者明确在说：**纯 kfunc ABI 不是这个抽象想要的东西。**

## 7.3 普通 kfunc 只能给你“call 一个函数”，而不是“在 bytecode 中保留一个 instruction site”

如果没有 `kinsn`，你最多能做到：

- 把 peephole pattern 改写成普通 `kfunc` 调用；
- 希望 JIT 再特殊识别这个 call 去做 inline emit。

但这样依然缺 3 个核心能力：

1. verifier 不会把它当 proof-visible instruction，只会走黑盒 call rule；
2. bytecode 中没有独立的 sidecar payload instruction form；
3. daemon 无法在不占用 R1-R5 ABI 的情况下，把 dst/src/off 等局部语义原样保留到后端。

换言之，**没有 kinsn，你可以伪装出“可 inline 的函数调用”；但你得不到“可验证、可恢复、可携带 operand payload 的指令形式”。**

---

## 8. 量化：当前仓库里到底有多少优化依赖 kinsn？

`PASS_REGISTRY` 一共注册了 12 个 pass：  
证据：`daemon/src/passes/mod.rs:52-118`

其中 **5 个直接依赖 kinsn packed transport**：

1. `bulk_memory`
2. `rotate`
3. `cond_select`
4. `extract`
5. `endian_fusion`

其余 **7 个是纯 bytecode 变换，不依赖 kinsn**：

1. `map_inline`
2. `const_prop`
3. `dce`
4. `skb_load_bytes_spec`
5. `bounds_check_merge`
6. `wide_mem`
7. `branch_flip`

特别是 `wide_mem` 的注释写得很直白：

> “No kinsn support needed -- pure BPF replacement.”

证据：`daemon/src/passes/wide_mem.rs:380-385`。

因此，从现有实现看：

- **kinsn 不是整个系统的必要条件**；
- 但它确实支撑了一组独立的、不可用纯 bytecode pass 替代的指令级 peephole 优化；
- reviewer 如果问 “到底多了什么新能力”，答案不是“所有优化都靠 kinsn”，而是“**某一类 instruction-form peephole optimization 需要它**”。

## 8.1 静态替换规模

| pass | 典型原始窗口 | BPF transport | native emit |
| --- | --- | --- | --- |
| rotate | 4 insns | 2 insns | x86 `mov+rol` / ARM64 `EXTR` |
| cond_select | 3 或 4 insns | 2 insns | x86 `test+cmov` / ARM64 `tst+csel` |
| extract | 2 insns | 2 insns | x86 inline extract seq / ARM64 `UBFM` |
| endian_fusion | 2 insns | 2 insns（少数场景 3-4） | x86 load+bswap / ARM64 load+REV |
| bulk_memory | 32B~128B 的长 store/load run | 每 chunk 2 insns | x86 `rep movsb/stosb` 或 ARM64 pair-loop |

这张表的重点不是所有 case 都是“N→1 machine insn”，而是：

- `kinsn` 把局部优化机会保留成一个独立的 instruction site；
- JIT 再把它降为短 native 序列；
- 中间没有普通函数调用 ABI 的寄存器搬运与 runtime call。

---

## 9. 给 reviewer 的直接回答

可以把回应压缩成下面这段：

> `kinsn` 复用了 `kfunc` 的注册与发现 plumbing，但它不是普通 `kfunc` 的语义别名。普通 `kfunc` 在 verifier 中是黑盒函数调用，安全模型只基于 BTF prototype 和 flags；当前 `kinsn` 则在主 verifier 之前被 lower 成 ordinary-BPF proof sequence，verifier 真正验证的是这段展开后的 BPF 语义，然后再把 site 恢复成原始 `sidecar + PSEUDO_KINSN_CALL` transport。JIT 阶段，普通 `kfunc` 仍是 runtime call 到 kernel symbol，而 `kinsn` 则根据 payload 直接内联 native code。因此，`kinsn` 的 novelty 不在于“又发明了一条注册 API”，而在于它把目标相关 peephole 优化提升成一种 verifier-visible、bytecode-carried、可原生发码又可回退 proof sequence 的 instruction-form abstraction。没有 kinsn，最多只能得到一个可 inline 的函数调用；得不到当前这种带 sidecar payload、proof-lowering、native emit dispatch 的独立指令抽象。`

---

## 10. 对论文措辞的建议

基于当前代码树，建议正文避免再使用下面这些说法：

- “`bpf_kinsn_effect` 是当前实现”
- “module 只声明 effect，core verifier 强制执行 effect”
- “当前 in-tree novelty 主要来自 declarative effect DSL”

更准确的表述应该是：

1. **当前实现的 novelty**：proof-visible instruction form + packed sidecar transport + native emit refinement + graceful degradation。
2. **不是 novelty 的部分**：kfunc registration plumbing 复用。
3. **如果想讨论 effect DSL**：应明确写成 future design / stronger design point，而不是 current implementation。

否则 reviewer 很容易抓住“文字说的是 effect DSL，代码实现其实是 proof-lowering”这一点。

---

## 11. 最终判断

如果严格基于当前代码树，我的结论是：

- **“kinsn 只是 kfunc + emit callback”这个说法不成立。**
- 但 **“kinsn 的 novelty 来自 declarative effect DSL”这个说法在当前 tree 也不成立。**

当前 tree 能站得住脚的 novelty，是：

1. **专用 bytecode transport**：`sidecar + PSEUDO_KINSN_CALL`
2. **独立 verifier 语义**：proof-lowering，而非黑盒 call
3. **独立 JIT 语义**：descriptor-driven native inline emit，而非 runtime symbol call
4. **双层 graceful degradation**：daemon 不改写 / kernel proof fallback

如果第 3 节按这个版本重写，reviewer 的质疑可以被正面化解；  
如果继续把当前实现写成 `bpf_kinsn_effect` 式的 effect DSL，就会留下明显的可攻击点。

diff --git a/docs/tmp/20260328/kinsn_vs_kfunc_novelty_20260328.md b/docs/tmp/20260328/kinsn_vs_kfunc_novelty_20260328.md
new file mode 100644
index 0000000000000000000000000000000000000000..f65466f4f3326c56196ecf1fa0829f5f1c240e23
--- /dev/null
++ b/docs/tmp/20260328/kinsn_vs_kfunc_novelty_20260328.md
@@ -0,0 +1,493 @@
# kinsn vs kfunc：本质差异与 novelty 论证

日期：2026-03-28  
目标：回应 reviewer 的质疑

> “如果 kinsn 本质上就是 kfunc + KF_INLINE_EMIT + emit callback，那第 3 节把它包装成独立 bytecode abstraction / extended ISA 就显得过度陈述。kinsn 相对已有 kfunc，到底多了什么不可替代的新能力？”

## 0. 先给结论

基于当前代码树，`kinsn` 不能被准确描述成“普通 kfunc 加一个 inline emit 回调”。  
它和普通 `kfunc` 的本质差异在于：

1. **语义源不同**：普通 `kfunc` 的 verifier 语义来自“BTF 原型 + flags”，函数体是黑盒；`kinsn` 的 verifier 语义来自 `instantiate_insn()` 生成的 ordinary-BPF proof sequence，verifier 真正逐条验证这段 proof sequence，而不是把它当黑盒 call。  
   代码证据：`vendor/linux-framework/include/linux/bpf.h:968-979`，`vendor/linux-framework/kernel/bpf/verifier.c:3669-3835`，`vendor/linux-framework/kernel/bpf/verifier.c:26408-26484`。

2. **抽象层级不同**：普通 `kfunc` 仍然是“函数调用”；`kinsn` 是“指令形式”的 transport。daemon 发出的不是 `BPF_PSEUDO_KFUNC_CALL`，而是“`sidecar + BPF_PSEUDO_KINSN_CALL`”这一对专用 bytecode 形式，payload 直接携带结果寄存器、输入寄存器、offset 等操作数字段。  
   代码证据：`daemon/src/insn.rs:243-290`，`vendor/linux-framework/include/linux/bpf.h:996-1007`，`vendor/linux-framework/kernel/bpf/verifier.c:21355-21476`。

3. **执行路径不同**：普通 `kfunc` 在 JIT 里被解析为真正的 runtime function call；`kinsn` 在 JIT 里根本不走函数地址调用，而是直接根据 descriptor + payload 发 native code。  
   代码证据：普通 `kfunc` 路径 `vendor/linux-framework/kernel/bpf/verifier.c:3542-3566` 与 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2477-2499`；`kinsn` 路径 `vendor/linux-framework/kernel/bpf/verifier.c:3524-3541`、`vendor/linux-framework/kernel/bpf/verifier.c:3882-3910`、`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:579-606`、`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2477-2483`。

4. **降级路径不同**：普通 `kfunc` 缺失时，调用点不可成立；BpfReJIT 的 `kinsn` pass 在 module/BTF 不可发现时直接不改写原程序，程序照常跑原始 eBPF；即便改写后缺少 native emit，kernel 也能回退到 proof sequence。  
   代码证据：`daemon/src/kfunc_discovery.rs:352-381`，`daemon/src/passes/rotate.rs:29-56`，`daemon/src/passes/cond_select.rs:143-171`，`vendor/linux-framework/kernel/bpf/verifier.c:23755-23795`。

因此，**复用 kfunc 注册/发现基础设施，只是 plumbing reuse；并不把 kinsn 降格成“普通 kfunc 的语义子集”**。  
真正独立存在的是三件东西：`sidecar` transport、proof-lowering verifier path、native emit dispatch。

---

## 1. 一个必须先纠正的前提：当前树里没有 `bpf_kinsn_effect / model_call`

题目背景里提到的 `bpf_kinsn_ops` / `bpf_kinsn_effect` / `model_call()`，**不是当前 in-tree 实现**。

当前 `include/linux/bpf.h` 里真正存在的是：

```c
struct bpf_kinsn {
	struct module *owner;
	u16 max_insn_cnt;
	u16 max_emit_bytes;
	int (*instantiate_insn)(u64 payload, struct bpf_insn *insn_buf);
	int (*emit_x86)(u8 *image, u32 *off, bool emit, u64 payload, const struct bpf_prog *prog);
	int (*emit_arm64)(u32 *image, int *idx, bool emit, u64 payload, const struct bpf_prog *prog);
};
```

代码证据：`vendor/linux-framework/include/linux/bpf.h:968-979`。  
设计文档也明确写了：**“There is no active `model_call()` or `bpf_kinsn_effect` path in the current tree.”**  
证据：`docs/kinsn-design.md:103-109`。

这意味着：

- 当前 tree 中，`kinsn` 的 verifier 语义不是 declarative effect DSL。
- 当前 tree 中，`kinsn` 的 verifier 语义来源是 `instantiate_insn()` 生成的 ordinary-BPF proof sequence。
- 因此，下面的 novelty 论证必须以 **proof-lowering model** 为准，而不能再按旧版 effect DSL 叙述。

这点很重要，因为 reviewer 如果按当前代码审读，你在正文里继续强调 `bpf_kinsn_effect`，会立刻被抓住“实现与论证不一致”。

---

## 2. 一张总表：普通 kfunc 与当前 kinsn 的真正差异

| 维度 | 普通 kfunc | 当前 kinsn |
| --- | --- | --- |
| 注册入口 | `register_btf_kfunc_id_set()` | 也复用 `register_btf_kfunc_id_set()`，但额外挂接 `kinsn_descs` |
| bytecode 编码 | `BPF_PSEUDO_KFUNC_CALL` | `sidecar + BPF_PSEUDO_KINSN_CALL` |
| verifier 看到什么 | call 指令；按 BTF prototype / flags 做参数与返回值建模 | 先被 lower 成 ordinary-BPF proof sequence，再跑标准 verifier |
| 语义源 | BTF 原型 + flags；函数体黑盒 | `instantiate_insn()` 生成的 proof sequence |
| JIT 执行 | 真实 `call` 到 kernel function 地址 | 直接 `emit_x86/emit_arm64` 内联发码 |
| 是否需要函数地址 | 需要：`kallsyms_lookup_name()` | 不需要：只需要 descriptor + payload |
| 操作数传递 | 走 R1-R5 调用 ABI，返回值在 R0 | payload 里直接携带 dst/src/off 等字段 |
| module 缺失时 | 调用点不可成立 | daemon 直接不改写原程序；已改写但无 native emit 时还能回退 proof sequence |
| 是否仍是“函数调用”抽象 | 是 | 否，已经是专用 instruction form |

对应代码：

- 复用注册入口但额外挂接 `kinsn_descs`：`vendor/linux-framework/include/linux/btf.h:122-127`，`vendor/linux-framework/kernel/bpf/btf.c:8784-8816`。
- 普通 `kfunc` 查到的是 `addr + func_model`：`vendor/linux-framework/kernel/bpf/verifier.c:3542-3566`。
- `kinsn` 查到的是 `desc->kinsn` 而不是函数地址：`vendor/linux-framework/kernel/bpf/verifier.c:3524-3541`。
- 普通 call bytecode 与 kinsn bytecode 区分：`daemon/src/insn.rs:223-255`。
- sidecar payload 编码：`daemon/src/insn.rs:277-290`，`vendor/linux-framework/include/linux/bpf.h:996-1007`。

---

## 3. “用 kfunc infra 实现”只是 plumbing reuse，不是语义等价

### 3.1 共享的是注册表，不是 verifier/JIT 语义

`kinsn` 的确复用了 kfunc 注册基础设施：

- `struct btf_kfunc_id_set` 多了 `const struct bpf_kinsn * const *kinsn_descs;`  
  证据：`vendor/linux-framework/include/linux/btf.h:122-127`
- 注册时，`btf_populate_kfunc_set()` 把 `(btf_id -> kinsn desc)` 填入独立的 `kinsn_sets`  
  证据：`vendor/linux-framework/kernel/bpf/btf.c:8784-8816`
- 查询时，`btf_kfunc_kinsn_desc()` 从这个附加表里取 descriptor  
  证据：`vendor/linux-framework/kernel/bpf/btf.c:8987-9005`

但是从 verifier 开始，普通 `kfunc` 与 `kinsn` 立即分叉：

- 普通 `kfunc` 分支：查 symbol 地址、蒸馏 `btf_func_model`、最终发出 runtime call  
  证据：`vendor/linux-framework/kernel/bpf/verifier.c:3542-3566`
- `kinsn` 分支：要求 `instantiate_insn != NULL`，保存 `desc->kinsn`，完全不取函数地址  
  证据：`vendor/linux-framework/kernel/bpf/verifier.c:3524-3541`

因此，**“用 kfunc infra 实现”只能推出 registration path 被复用，不能推出 semantic abstraction 没有新东西**。

### 3.2 如果将来统一到 kfunc 路径，也不等于 kinsn 不需要独立存在

即使把 `PSEUDO_KINSN_CALL` 统一编码到 `PSEUDO_KFUNC_CALL`，只要下面三样还在，`kinsn` 仍是独立抽象：

1. sidecar payload transport
2. proof-lowering verifier path
3. native emit dispatch

换句话说，**可以统一 plumbing，但不能消掉 abstraction**。  
消掉这三样之后，剩下的才只是“普通 kfunc 调用”。

---

## 4. verifier 本质差异：普通 kfunc 是黑盒 call，kinsn 是 proof-visible instruction

## 4.1 普通 kfunc：verifier 不看函数体，只看原型/flags

普通 `kfunc` 的元数据来自：

- BTF function prototype
- kfunc flags
- 允许性检查

证据：

- `fetch_kfunc_meta()` 从 BTF 取 `func_proto`、`func_name`、`kfunc_flags`：`vendor/linux-framework/kernel/bpf/verifier.c:3405-3449`
- `fetch_kfunc_arg_meta()` 只把 `btf/proto/name/flags` 填入 `meta`：`vendor/linux-framework/kernel/bpf/verifier.c:14203-14226`
- `check_kfunc_args()` 逐个参数按 BTF 类型做检查：`vendor/linux-framework/kernel/bpf/verifier.c:13656-14120`
- 返回值按 BTF 返回类型建模：`vendor/linux-framework/kernel/bpf/verifier.c:14650-14779`
- 调用后统一 clobber caller-saved regs：`vendor/linux-framework/kernel/bpf/verifier.c:14643-14648`

普通 `kfunc` descriptor 里保存的是：

```c
struct bpf_kfunc_desc {
	struct btf_func_model func_model;
	const struct bpf_kinsn *kinsn;
	u32 func_id;
	s32 imm;
	u16 offset;
	unsigned long addr;
};
```

证据：`vendor/linux-framework/kernel/bpf/verifier.c:3180-3187`。

对普通 `kfunc`，最终被填充的是 `addr` 和 `func_model`，而不是 `kinsn`：

- `addr = kallsyms_lookup_name(kfunc.name)`  
- `btf_distill_func_proto(..., &func_model)`  
- `desc->addr = addr; desc->func_model = func_model;`

证据：`vendor/linux-framework/kernel/bpf/verifier.c:3542-3566`，`vendor/linux-framework/kernel/bpf/btf.c:7485-7553`。

这说明普通 `kfunc` 的 verifier 视角始终是：“这是一个黑盒函数调用；我只知道签名，不知道函数体。”

## 4.2 kinsn：verifier 真正验证的是 instantiated proof sequence

`kinsn` 走的是完全不同的路径：

1. `add_subprog_and_kfunc()` 识别 `BPF_PSEUDO_KINSN_CALL`，统计 `env->kinsn_call_cnt`，并以 `kinsn_call=true` 注册 descriptor。  
   证据：`vendor/linux-framework/kernel/bpf/verifier.c:3928-3963`

2. `lower_kinsn_proof_regions()` 在主 verifier 之前，把每个 `sidecar + kinsn_call` 替换成 `instantiate_insn(payload)` 生成的 proof sequence。  
   证据：`vendor/linux-framework/kernel/bpf/verifier.c:3723-3835`

3. verifier 随后对 lowered 程序跑标准流程：`check_subprogs()`、`check_cfg()`、`compute_postorder()`、`compute_scc()`、`compute_live_registers()`、`do_check_main()`、`do_check_subprogs()`。  
   证据：`vendor/linux-framework/kernel/bpf/verifier.c:26408-26484`

4. 验证成功后，再 `restore_kinsn_proof_regions()` 把 proof sequence 恢复回原始 sidecar+call transport。  
   证据：`vendor/linux-framework/kernel/bpf/verifier.c:3837-3879`，`vendor/linux-framework/kernel/bpf/verifier.c:26479-26484`

还要注意两条非常强的证据：

- verifier 明确禁止“未 lowering 的 kinsn call”继续走普通 call 检查：  
  `internal error: kinsn call reached verifier without proof lowering`  
  证据：`vendor/linux-framework/kernel/bpf/verifier.c:21474-21476`

- `check_kinsn_sidecar_insn()` 只做 transport 完整性检查，要求 sidecar 后面必须立刻跟 kinsn call。  
  证据：`vendor/linux-framework/kernel/bpf/verifier.c:21355-21372`

所以，**当前 tree 中 kinsn 的 verifier 语义来源不是 call rule，而是 proof-lowering 后的 ordinary BPF**。  
这已经足以把它和普通 `kfunc` 区分开。

## 4.3 这比“普通 kfunc + emit callback”多了什么？

多出来的是：**call 站点不再被 verifier 当作 opaque function invocation，而被当作一个可以展开、验证、恢复的 instruction-form object。**

这正是 reviewer 质疑中的关键误区。  
如果只是“普通 kfunc + emit callback”，verifier 侧仍然会停留在 `check_kfunc_call()` 这条黑盒语义路径上。  
当前 `kinsn` 不是这样；它有一整条独立的 proof-lowering verifier path。

## 4.4 需要诚实加上的一个 caveat

如果按你最初的 `bpf_kinsn_effect` 说法，结论会更强：module 只能声明 effect，core verifier 强制执行 effect。  
**但这不是当前 tree 的实现。**

当前 tree 的真实安全叙述应更精确地写成：

- **BPF-visible safety** 来自 ordinary-BPF proof sequence 的标准 verifier；
- **native correctness** 额外依赖 `emit_x86/emit_arm64` 对 `instantiate_insn()` 的 refinement。

也就是说，当前 tree 确实比普通 `kfunc` 更“可验证”，但它的 novelty 是 **proof-visible instruction semantics**，不是更强的 **effect-DSL trust narrowing**。

---

## 5. 抽象层级差异：函数调用 vs 指令形式

## 5.1 普通 kfunc 仍然是 call ABI

普通 BPF call 的 helper/kfunc 原型是固定走寄存器 ABI 的：`func(u64 r1, u64 r2, u64 r3, u64 r4, u64 r5)`。  
证据：`vendor/linux-framework/include/linux/bpf.h:924-965`。

如果把一个局部 peephole 重写成普通 `kfunc`，即便语义上可行，也仍然要承担：

- 参数搬运到 R1-R5
- runtime `call` / `ret`
- 返回值从 R0 再搬回目标寄存器
- caller-saved clobber 语义

这仍然是**函数级**抽象。

## 5.2 kinsn transport 是专用 instruction form

daemon 发出的 kinsn 不是普通 call，而是：

1. `BpfInsn::kinsn_sidecar(payload)`
2. `BpfInsn::call_kinsn_with_off(btf_id, off)`

证据：`daemon/src/passes/utils.rs:281-292`，`daemon/src/insn.rs:243-290`。

payload 直接编码：

- 结果寄存器
- 输入寄存器
- offset
- 立即数参数

因此，**operand/result placement 是 payload-level，而不是 ABI-level**。

`emit_packed_kinsn_call_with_off()` 的注释甚至明确写了：

> “The result register is part of `payload`, so no extra `mov dst, r0` is emitted here.”

证据：`daemon/src/passes/utils.rs:281-292`。

这就是为什么它是 instruction abstraction，而不是 function abstraction。

## 5.3 具体 pass 里，替换粒度就是 instruction-form 粒度

### rotate

- 识别的是 `MOV provenance + RSH + LSH + OR` 窗口  
  证据：`daemon/src/passes/rotate.rs:239-360`
- `old_len = (pc + 3) - mov_pc`，即典型 4→2 BPF transport 替换  
  证据：`daemon/src/passes/rotate.rs:294-309`
- native emit 不是函数调用，而是 x86 `mov + rol` 或 ARM64 `EXTR`  
  证据：`module/x86/bpf_rotate.c:95-125`，`module/arm64/bpf_rotate.c:68-95`

### cond_select

- 识别 4-insn diamond 或 3-insn short pattern  
  证据：`daemon/src/passes/cond_select.rs:327-411`
- `old_len` 分别为 4 或 3  
  证据：`daemon/src/passes/cond_select.rs:361`，`daemon/src/passes/cond_select.rs:411`
- native emit 是 x86 `test + cmov` 或 ARM64 `tst + csel`  
  证据：`module/x86/bpf_select.c:102-146`，`module/arm64/bpf_select.c:71-105`

### extract

- 识别 `RSH + AND` 两条指令  
  证据：`daemon/src/passes/extract.rs:55-94`
- `old_len = 2`，替换成 2-insn transport  
  证据：`daemon/src/passes/extract.rs:77-83`，`daemon/src/passes/extract.rs:196-200`
- native emit 是直接内联 bitfield extract sequence，而不是 helper body call  
  证据：`module/x86/bpf_extract.c:96-127`，`module/arm64/bpf_extract.c:64-90`

### endian_fusion

- 识别 `LDX_MEM + ENDIAN_TO_BE`  
  证据：`daemon/src/passes/endian.rs:17-33`，`daemon/src/passes/endian.rs:53-107`
- 直接把 offset 编进 payload；必要时也只是在 packed transport 周围补地址物化，而不是切回 legacy call ABI  
  证据：`daemon/src/passes/endian.rs:155-210`
- 注释明确说“instead of using any legacy call ABI”  
  证据：`daemon/src/passes/endian.rs:30-33`

### bulk_memory

- 识别大段 scalarized memcpy/memset  
  证据：`daemon/src/passes/bulk_memory.rs:92-93`
- `MIN_BULK_BYTES = 32`，`CHUNK_MAX_BYTES = 128`  
  证据：`daemon/src/passes/bulk_memory.rs:12-18`
- 每个 chunk 仅发出 `2` 条 transport 指令  
  证据：`daemon/src/passes/bulk_memory.rs:529-547`，`daemon/src/passes/bulk_memory.rs:557-573`
- verifier proof sequence 却可以展开为最多 `128*2` 条 bytewise memcpy 指令  
  证据：`module/x86/bpf_bulk_memory.c:131-150`，`module/x86/bpf_bulk_memory.c:449-455`

这类“**大窗口 -> 单个逻辑指令 -> 小 native 序列**”的替换，正是普通 `kfunc` 难以等价替代的地方。

---

## 6. 优雅降级：这也是普通 kfunc 不具备的产品级属性

## 6.1 module 没加载时，daemon 直接保持原始 bytecode

discovery 阶段如果 `/sys/kernel/btf/<module>` 不存在，就把该 target 标成 unavailable：

- `module '<name>' not loaded (no BTF at ...)`
- 对应 `registry.*_btf_id` 保持 `-1`

证据：`daemon/src/kfunc_discovery.rs:311-381`。

各 pass 在发现 target 不可用时，直接 `changed=false` 返回，不改原程序：

- rotate：`daemon/src/passes/rotate.rs:29-41`
- cond_select：`daemon/src/passes/cond_select.rs:143-171`
- extract：`daemon/src/passes/extract.rs:111-138`
- endian_fusion：`daemon/src/passes/endian.rs:228-266`
- bulk_memory：`daemon/src/passes/bulk_memory.rs:151-175`

这意味着 **module 缺失不会导致应用程序不能运行，只会让优化 pass 不生效**。

## 6.2 module 存在但当前架构/后端没有 native emit 时，kernel 回退到 proof sequence

在 `do_misc_fixups()` 里：

- 若 `prog->jit_requested && bpf_kinsn_has_native_emit(kinsn)`，保留 sidecar+call 给 JIT 原生发码；
- 否则，就把 sidecar+call 替换成 `instantiate_insn()` 生成的 proof sequence。

证据：`vendor/linux-framework/kernel/bpf/verifier.c:23755-23795`。

所以 kinsn 有两层 graceful degradation：

1. **用户态 pass 层**：没发现 module，就不改写
2. **内核 JIT 层**：发现了 kinsn 但没 native emit，也还能退回 ordinary BPF

这比“硬依赖某个 kfunc 必须存在，否则 load fail”更平滑。

---

## 7. “纯用 kfunc 能不能做出同样效果？”答案是：不能等价复制当前实现的关键性质

## 7.1 代码已经表明这些 pass 依赖的是 packed kinsn，而不是普通 kfunc

当前真正使用 `emit_packed_kinsn_call_with_off()` 的 pass 一共有 5 个：

1. `bulk_memory`
2. `rotate`
3. `cond_select`
4. `extract`
5. `endian_fusion`

证据：

- `daemon/src/passes/bulk_memory.rs`
- `daemon/src/passes/rotate.rs`
- `daemon/src/passes/cond_select.rs`
- `daemon/src/passes/extract.rs`
- `daemon/src/passes/endian.rs`

这些 pass 发出的都是 `BPF_PSEUDO_KINSN_CALL`，不是 `BPF_PSEUDO_KFUNC_CALL`。  
证据：`daemon/src/passes/utils.rs:281-292`，以及各 pass 的 replacement 构造代码。

## 7.2 某些 pass 明确拒绝回退到 legacy call ABI

最清楚的是 `endian_fusion` 和 `cond_select`：

- `endian_fusion` 注释明确说，即便 offset 不能直接编码，也是在 packed transport 周围补地址计算，**“instead of using any legacy call ABI”**。  
  证据：`daemon/src/passes/endian.rs:30-33`

- `cond_select` 如果 true/false 不是寄存器值，就直接 skip，原因是 packed path 需要 register operands；它没有实现任何“普通 kfunc ABI fallback”。  
  证据：`daemon/src/passes/cond_select.rs:104-111`，`daemon/src/passes/cond_select.rs:227-233`

这不是偶然，而是实现者明确在说：**纯 kfunc ABI 不是这个抽象想要的东西。**

## 7.3 普通 kfunc 只能给你“call 一个函数”，而不是“在 bytecode 中保留一个 instruction site”

如果没有 `kinsn`，你最多能做到：

- 把 peephole pattern 改写成普通 `kfunc` 调用；
- 希望 JIT 再特殊识别这个 call 去做 inline emit。

但这样依然缺 3 个核心能力：

1. verifier 不会把它当 proof-visible instruction，只会走黑盒 call rule；
2. bytecode 中没有独立的 sidecar payload instruction form；
3. daemon 无法在不占用 R1-R5 ABI 的情况下，把 dst/src/off 等局部语义原样保留到后端。

换言之，**没有 kinsn，你可以伪装出“可 inline 的函数调用”；但你得不到“可验证、可恢复、可携带 operand payload 的指令形式”。**

---

## 8. 量化：当前仓库里到底有多少优化依赖 kinsn？

`PASS_REGISTRY` 一共注册了 12 个 pass：  
证据：`daemon/src/passes/mod.rs:52-118`

其中 **5 个直接依赖 kinsn packed transport**：

1. `bulk_memory`
2. `rotate`
3. `cond_select`
4. `extract`
5. `endian_fusion`

其余 **7 个是纯 bytecode 变换，不依赖 kinsn**：

1. `map_inline`
2. `const_prop`
3. `dce`
4. `skb_load_bytes_spec`
5. `bounds_check_merge`
6. `wide_mem`
7. `branch_flip`

特别是 `wide_mem` 的注释写得很直白：

> “No kinsn support needed -- pure BPF replacement.”

证据：`daemon/src/passes/wide_mem.rs:380-385`。

因此，从现有实现看：

- **kinsn 不是整个系统的必要条件**；
- 但它确实支撑了一组独立的、不可用纯 bytecode pass 替代的指令级 peephole 优化；
- reviewer 如果问 “到底多了什么新能力”，答案不是“所有优化都靠 kinsn”，而是“**某一类 instruction-form peephole optimization 需要它**”。

## 8.1 静态替换规模

| pass | 典型原始窗口 | BPF transport | native emit |
| --- | --- | --- | --- |
| rotate | 4 insns | 2 insns | x86 `mov+rol` / ARM64 `EXTR` |
| cond_select | 3 或 4 insns | 2 insns | x86 `test+cmov` / ARM64 `tst+csel` |
| extract | 2 insns | 2 insns | x86 inline extract seq / ARM64 `UBFM` |
| endian_fusion | 2 insns | 2 insns（少数场景 3-4） | x86 load+bswap / ARM64 load+REV |
| bulk_memory | 32B~128B 的长 store/load run | 每 chunk 2 insns | x86 `rep movsb/stosb` 或 ARM64 pair-loop |

这张表的重点不是所有 case 都是“N→1 machine insn”，而是：

- `kinsn` 把局部优化机会保留成一个独立的 instruction site；
- JIT 再把它降为短 native 序列；
- 中间没有普通函数调用 ABI 的寄存器搬运与 runtime call。

---

## 9. 给 reviewer 的直接回答

可以把回应压缩成下面这段：

> `kinsn` 复用了 `kfunc` 的注册与发现 plumbing，但它不是普通 `kfunc` 的语义别名。普通 `kfunc` 在 verifier 中是黑盒函数调用，安全模型只基于 BTF prototype 和 flags；当前 `kinsn` 则在主 verifier 之前被 lower 成 ordinary-BPF proof sequence，verifier 真正验证的是这段展开后的 BPF 语义，然后再把 site 恢复成原始 `sidecar + PSEUDO_KINSN_CALL` transport。JIT 阶段，普通 `kfunc` 仍是 runtime call 到 kernel symbol，而 `kinsn` 则根据 payload 直接内联 native code。因此，`kinsn` 的 novelty 不在于“又发明了一条注册 API”，而在于它把目标相关 peephole 优化提升成一种 verifier-visible、bytecode-carried、可原生发码又可回退 proof sequence 的 instruction-form abstraction。没有 kinsn，最多只能得到一个可 inline 的函数调用；得不到当前这种带 sidecar payload、proof-lowering、native emit dispatch 的独立指令抽象。`

---

## 10. 对论文措辞的建议

基于当前代码树，建议正文避免再使用下面这些说法：

- “`bpf_kinsn_effect` 是当前实现”
- “module 只声明 effect，core verifier 强制执行 effect”
- “当前 in-tree novelty 主要来自 declarative effect DSL”

更准确的表述应该是：

1. **当前实现的 novelty**：proof-visible instruction form + packed sidecar transport + native emit refinement + graceful degradation。
2. **不是 novelty 的部分**：kfunc registration plumbing 复用。
3. **如果想讨论 effect DSL**：应明确写成 future design / stronger design point，而不是 current implementation。

否则 reviewer 很容易抓住“文字说的是 effect DSL，代码实现其实是 proof-lowering”这一点。

---

## 11. 最终判断

如果严格基于当前代码树，我的结论是：

- **“kinsn 只是 kfunc + emit callback”这个说法不成立。**
- 但 **“kinsn 的 novelty 来自 declarative effect DSL”这个说法在当前 tree 也不成立。**

当前 tree 能站得住脚的 novelty，是：

1. **专用 bytecode transport**：`sidecar + PSEUDO_KINSN_CALL`
2. **独立 verifier 语义**：proof-lowering，而非黑盒 call
3. **独立 JIT 语义**：descriptor-driven native inline emit，而非 runtime symbol call
4. **双层 graceful degradation**：daemon 不改写 / kernel proof fallback

如果第 3 节按这个版本重写，reviewer 的质疑可以被正面化解；  
如果继续把当前实现写成 `bpf_kinsn_effect` 式的 effect DSL，就会留下明显的可攻击点。

context compacted
codex
我已经把文档按当前代码实现写到临时目录了，先复核一遍内容和引用，确认没有把已经过时的 `bpf_kinsn_effect/model_call` 叙述误写成现状。
exec
/bin/bash -lc "sed -n '1,260p' /home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/kinsn_vs_kfunc_novelty_20260328.md" in /home/yunwei37/workspace/bpf-benchmark
 succeeded in 0ms:
# kinsn vs kfunc：本质差异与 novelty 论证

日期：2026-03-28  
目标：回应 reviewer 的质疑

> “如果 kinsn 本质上就是 kfunc + KF_INLINE_EMIT + emit callback，那第 3 节把它包装成独立 bytecode abstraction / extended ISA 就显得过度陈述。kinsn 相对已有 kfunc，到底多了什么不可替代的新能力？”

## 0. 先给结论

基于当前代码树，`kinsn` 不能被准确描述成“普通 kfunc 加一个 inline emit 回调”。  
它和普通 `kfunc` 的本质差异在于：

1. **语义源不同**：普通 `kfunc` 的 verifier 语义来自“BTF 原型 + flags”，函数体是黑盒；`kinsn` 的 verifier 语义来自 `instantiate_insn()` 生成的 ordinary-BPF proof sequence，verifier 真正逐条验证这段 proof sequence，而不是把它当黑盒 call。  
   代码证据：`vendor/linux-framework/include/linux/bpf.h:968-979`，`vendor/linux-framework/kernel/bpf/verifier.c:3669-3835`，`vendor/linux-framework/kernel/bpf/verifier.c:26408-26484`。

2. **抽象层级不同**：普通 `kfunc` 仍然是“函数调用”；`kinsn` 是“指令形式”的 transport。daemon 发出的不是 `BPF_PSEUDO_KFUNC_CALL`，而是“`sidecar + BPF_PSEUDO_KINSN_CALL`”这一对专用 bytecode 形式，payload 直接携带结果寄存器、输入寄存器、offset 等操作数字段。  
   代码证据：`daemon/src/insn.rs:243-290`，`vendor/linux-framework/include/linux/bpf.h:996-1007`，`vendor/linux-framework/kernel/bpf/verifier.c:21355-21476`。

3. **执行路径不同**：普通 `kfunc` 在 JIT 里被解析为真正的 runtime function call；`kinsn` 在 JIT 里根本不走函数地址调用，而是直接根据 descriptor + payload 发 native code。  
   代码证据：普通 `kfunc` 路径 `vendor/linux-framework/kernel/bpf/verifier.c:3542-3566` 与 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2477-2499`；`kinsn` 路径 `vendor/linux-framework/kernel/bpf/verifier.c:3524-3541`、`vendor/linux-framework/kernel/bpf/verifier.c:3882-3910`、`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:579-606`、`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2477-2483`。

4. **降级路径不同**：普通 `kfunc` 缺失时，调用点不可成立；BpfReJIT 的 `kinsn` pass 在 module/BTF 不可发现时直接不改写原程序，程序照常跑原始 eBPF；即便改写后缺少 native emit，kernel 也能回退到 proof sequence。  
   代码证据：`daemon/src/kfunc_discovery.rs:352-381`，`daemon/src/passes/rotate.rs:29-56`，`daemon/src/passes/cond_select.rs:143-171`，`vendor/linux-framework/kernel/bpf/verifier.c:23755-23795`。

因此，**复用 kfunc 注册/发现基础设施，只是 plumbing reuse；并不把 kinsn 降格成“普通 kfunc 的语义子集”**。  
真正独立存在的是三件东西：`sidecar` transport、proof-lowering verifier path、native emit dispatch。

---

## 1. 一个必须先纠正的前提：当前树里没有 `bpf_kinsn_effect / model_call`

题目背景里提到的 `bpf_kinsn_ops` / `bpf_kinsn_effect` / `model_call()`，**不是当前 in-tree 实现**。

当前 `include/linux/bpf.h` 里真正存在的是：

```c
struct bpf_kinsn {
	struct module *owner;
	u16 max_insn_cnt;
	u16 max_emit_bytes;
	int (*instantiate_insn)(u64 payload, struct bpf_insn *insn_buf);
	int (*emit_x86)(u8 *image, u32 *off, bool emit, u64 payload, const struct bpf_prog *prog);
	int (*emit_arm64)(u32 *image, int *idx, bool emit, u64 payload, const struct bpf_prog *prog);
};
```

代码证据：`vendor/linux-framework/include/linux/bpf.h:968-979`。  
设计文档也明确写了：**“There is no active `model_call()` or `bpf_kinsn_effect` path in the current tree.”**  
证据：`docs/kinsn-design.md:103-109`。

这意味着：

- 当前 tree 中，`kinsn` 的 verifier 语义不是 declarative effect DSL。
- 当前 tree 中，`kinsn` 的 verifier 语义来源是 `instantiate_insn()` 生成的 ordinary-BPF proof sequence。
- 因此，下面的 novelty 论证必须以 **proof-lowering model** 为准，而不能再按旧版 effect DSL 叙述。

这点很重要，因为 reviewer 如果按当前代码审读，你在正文里继续强调 `bpf_kinsn_effect`，会立刻被抓住“实现与论证不一致”。

---

## 2. 一张总表：普通 kfunc 与当前 kinsn 的真正差异

| 维度 | 普通 kfunc | 当前 kinsn |
| --- | --- | --- |
| 注册入口 | `register_btf_kfunc_id_set()` | 也复用 `register_btf_kfunc_id_set()`，但额外挂接 `kinsn_descs` |
| bytecode 编码 | `BPF_PSEUDO_KFUNC_CALL` | `sidecar + BPF_PSEUDO_KINSN_CALL` |
| verifier 看到什么 | call 指令；按 BTF prototype / flags 做参数与返回值建模 | 先被 lower 成 ordinary-BPF proof sequence，再跑标准 verifier |
| 语义源 | BTF 原型 + flags；函数体黑盒 | `instantiate_insn()` 生成的 proof sequence |
| JIT 执行 | 真实 `call` 到 kernel function 地址 | 直接 `emit_x86/emit_arm64` 内联发码 |
| 是否需要函数地址 | 需要：`kallsyms_lookup_name()` | 不需要：只需要 descriptor + payload |
| 操作数传递 | 走 R1-R5 调用 ABI，返回值在 R0 | payload 里直接携带 dst/src/off 等字段 |
| module 缺失时 | 调用点不可成立 | daemon 直接不改写原程序；已改写但无 native emit 时还能回退 proof sequence |
| 是否仍是“函数调用”抽象 | 是 | 否，已经是专用 instruction form |

对应代码：

- 复用注册入口但额外挂接 `kinsn_descs`：`vendor/linux-framework/include/linux/btf.h:122-127`，`vendor/linux-framework/kernel/bpf/btf.c:8784-8816`。
- 普通 `kfunc` 查到的是 `addr + func_model`：`vendor/linux-framework/kernel/bpf/verifier.c:3542-3566`。
- `kinsn` 查到的是 `desc->kinsn` 而不是函数地址：`vendor/linux-framework/kernel/bpf/verifier.c:3524-3541`。
- 普通 call bytecode 与 kinsn bytecode 区分：`daemon/src/insn.rs:223-255`。
- sidecar payload 编码：`daemon/src/insn.rs:277-290`，`vendor/linux-framework/include/linux/bpf.h:996-1007`。

---

## 3. “用 kfunc infra 实现”只是 plumbing reuse，不是语义等价

### 3.1 共享的是注册表，不是 verifier/JIT 语义

`kinsn` 的确复用了 kfunc 注册基础设施：

- `struct btf_kfunc_id_set` 多了 `const struct bpf_kinsn * const *kinsn_descs;`  
  证据：`vendor/linux-framework/include/linux/btf.h:122-127`
- 注册时，`btf_populate_kfunc_set()` 把 `(btf_id -> kinsn desc)` 填入独立的 `kinsn_sets`  
  证据：`vendor/linux-framework/kernel/bpf/btf.c:8784-8816`
- 查询时，`btf_kfunc_kinsn_desc()` 从这个附加表里取 descriptor  
  证据：`vendor/linux-framework/kernel/bpf/btf.c:8987-9005`

但是从 verifier 开始，普通 `kfunc` 与 `kinsn` 立即分叉：

- 普通 `kfunc` 分支：查 symbol 地址、蒸馏 `btf_func_model`、最终发出 runtime call  
  证据：`vendor/linux-framework/kernel/bpf/verifier.c:3542-3566`
- `kinsn` 分支：要求 `instantiate_insn != NULL`，保存 `desc->kinsn`，完全不取函数地址  
  证据：`vendor/linux-framework/kernel/bpf/verifier.c:3524-3541`

因此，**“用 kfunc infra 实现”只能推出 registration path 被复用，不能推出 semantic abstraction 没有新东西**。

### 3.2 如果将来统一到 kfunc 路径，也不等于 kinsn 不需要独立存在

即使把 `PSEUDO_KINSN_CALL` 统一编码到 `PSEUDO_KFUNC_CALL`，只要下面三样还在，`kinsn` 仍是独立抽象：

1. sidecar payload transport
2. proof-lowering verifier path
3. native emit dispatch

换句话说，**可以统一 plumbing，但不能消掉 abstraction**。  
消掉这三样之后，剩下的才只是“普通 kfunc 调用”。

---

## 4. verifier 本质差异：普通 kfunc 是黑盒 call，kinsn 是 proof-visible instruction

## 4.1 普通 kfunc：verifier 不看函数体，只看原型/flags

普通 `kfunc` 的元数据来自：

- BTF function prototype
- kfunc flags
- 允许性检查

证据：

- `fetch_kfunc_meta()` 从 BTF 取 `func_proto`、`func_name`、`kfunc_flags`：`vendor/linux-framework/kernel/bpf/verifier.c:3405-3449`
- `fetch_kfunc_arg_meta()` 只把 `btf/proto/name/flags` 填入 `meta`：`vendor/linux-framework/kernel/bpf/verifier.c:14203-14226`
- `check_kfunc_args()` 逐个参数按 BTF 类型做检查：`vendor/linux-framework/kernel/bpf/verifier.c:13656-14120`
- 返回值按 BTF 返回类型建模：`vendor/linux-framework/kernel/bpf/verifier.c:14650-14779`
- 调用后统一 clobber caller-saved regs：`vendor/linux-framework/kernel/bpf/verifier.c:14643-14648`

普通 `kfunc` descriptor 里保存的是：

```c
struct bpf_kfunc_desc {
	struct btf_func_model func_model;
	const struct bpf_kinsn *kinsn;
	u32 func_id;
	s32 imm;
	u16 offset;
	unsigned long addr;
};
```

证据：`vendor/linux-framework/kernel/bpf/verifier.c:3180-3187`。

对普通 `kfunc`，最终被填充的是 `addr` 和 `func_model`，而不是 `kinsn`：

- `addr = kallsyms_lookup_name(kfunc.name)`  
- `btf_distill_func_proto(..., &func_model)`  
- `desc->addr = addr; desc->func_model = func_model;`

证据：`vendor/linux-framework/kernel/bpf/verifier.c:3542-3566`，`vendor/linux-framework/kernel/bpf/btf.c:7485-7553`。

这说明普通 `kfunc` 的 verifier 视角始终是：“这是一个黑盒函数调用；我只知道签名，不知道函数体。”

## 4.2 kinsn：verifier 真正验证的是 instantiated proof sequence

`kinsn` 走的是完全不同的路径：

1. `add_subprog_and_kfunc()` 识别 `BPF_PSEUDO_KINSN_CALL`，统计 `env->kinsn_call_cnt`，并以 `kinsn_call=true` 注册 descriptor。  
   证据：`vendor/linux-framework/kernel/bpf/verifier.c:3928-3963`

2. `lower_kinsn_proof_regions()` 在主 verifier 之前，把每个 `sidecar + kinsn_call` 替换成 `instantiate_insn(payload)` 生成的 proof sequence。  
   证据：`vendor/linux-framework/kernel/bpf/verifier.c:3723-3835`

3. verifier 随后对 lowered 程序跑标准流程：`check_subprogs()`、`check_cfg()`、`compute_postorder()`、`compute_scc()`、`compute_live_registers()`、`do_check_main()`、`do_check_subprogs()`。  
   证据：`vendor/linux-framework/kernel/bpf/verifier.c:26408-26484`

4. 验证成功后，再 `restore_kinsn_proof_regions()` 把 proof sequence 恢复回原始 sidecar+call transport。  
   证据：`vendor/linux-framework/kernel/bpf/verifier.c:3837-3879`，`vendor/linux-framework/kernel/bpf/verifier.c:26479-26484`

还要注意两条非常强的证据：

- verifier 明确禁止“未 lowering 的 kinsn call”继续走普通 call 检查：  
  `internal error: kinsn call reached verifier without proof lowering`  
  证据：`vendor/linux-framework/kernel/bpf/verifier.c:21474-21476`

- `check_kinsn_sidecar_insn()` 只做 transport 完整性检查，要求 sidecar 后面必须立刻跟 kinsn call。  
  证据：`vendor/linux-framework/kernel/bpf/verifier.c:21355-21372`

所以，**当前 tree 中 kinsn 的 verifier 语义来源不是 call rule，而是 proof-lowering 后的 ordinary BPF**。  
这已经足以把它和普通 `kfunc` 区分开。

## 4.3 这比“普通 kfunc + emit callback”多了什么？

多出来的是：**call 站点不再被 verifier 当作 opaque function invocation，而被当作一个可以展开、验证、恢复的 instruction-form object。**

这正是 reviewer 质疑中的关键误区。  
如果只是“普通 kfunc + emit callback”，verifier 侧仍然会停留在 `check_kfunc_call()` 这条黑盒语义路径上。  
当前 `kinsn` 不是这样；它有一整条独立的 proof-lowering verifier path。

## 4.4 需要诚实加上的一个 caveat

如果按你最初的 `bpf_kinsn_effect` 说法，结论会更强：module 只能声明 effect，core verifier 强制执行 effect。  
**但这不是当前 tree 的实现。**

当前 tree 的真实安全叙述应更精确地写成：

- **BPF-visible safety** 来自 ordinary-BPF proof sequence 的标准 verifier；
- **native correctness** 额外依赖 `emit_x86/emit_arm64` 对 `instantiate_insn()` 的 refinement。

也就是说，当前 tree 确实比普通 `kfunc` 更“可验证”，但它的 novelty 是 **proof-visible instruction semantics**，不是更强的 **effect-DSL trust narrowing**。

---

## 5. 抽象层级差异：函数调用 vs 指令形式

## 5.1 普通 kfunc 仍然是 call ABI

普通 BPF call 的 helper/kfunc 原型是固定走寄存器 ABI 的：`func(u64 r1, u64 r2, u64 r3, u64 r4, u64 r5)`。  
证据：`vendor/linux-framework/include/linux/bpf.h:924-965`。

如果把一个局部 peephole 重写成普通 `kfunc`，即便语义上可行，也仍然要承担：

- 参数搬运到 R1-R5
- runtime `call` / `ret`
- 返回值从 R0 再搬回目标寄存器
- caller-saved clobber 语义

这仍然是**函数级**抽象。

## 5.2 kinsn transport 是专用 instruction form

daemon 发出的 kinsn 不是普通 call，而是：

1. `BpfInsn::kinsn_sidecar(payload)`
2. `BpfInsn::call_kinsn_with_off(btf_id, off)`

证据：`daemon/src/passes/utils.rs:281-292`，`daemon/src/insn.rs:243-290`。

payload 直接编码：

- 结果寄存器
- 输入寄存器
- offset
- 立即数参数

因此，**operand/result placement 是 payload-level，而不是 ABI-level**。

`emit_packed_kinsn_call_with_off()` 的注释甚至明确写了：

> “The result register is part of `payload`, so no extra `mov dst, r0` is emitted here.”

证据：`daemon/src/passes/utils.rs:281-292`。

这就是为什么它是 instruction abstraction，而不是 function abstraction。

## 5.3 具体 pass 里，替换粒度就是 instruction-form 粒度

### rotate

- 识别的是 `MOV provenance + RSH + LSH + OR` 窗口  
  证据：`daemon/src/passes/rotate.rs:239-360`

exec
/bin/bash -lc 'git -C /home/yunwei37/workspace/bpf-benchmark status --short docs/tmp/20260328/kinsn_vs_kfunc_novelty_20260328.md' in /home/yunwei37/workspace/bpf-benchmark
 succeeded in 0ms:
?? docs/tmp/20260328/kinsn_vs_kfunc_novelty_20260328.md

diff --git a/docs/tmp/20260328/kinsn_vs_kfunc_novelty_20260328.md b/docs/tmp/20260328/kinsn_vs_kfunc_novelty_20260328.md
new file mode 100644
index 0000000000000000000000000000000000000000..f65466f4f3326c56196ecf1fa0829f5f1c240e23
--- /dev/null
++ b/docs/tmp/20260328/kinsn_vs_kfunc_novelty_20260328.md
@@ -0,0 +1,493 @@
# kinsn vs kfunc：本质差异与 novelty 论证

日期：2026-03-28  
目标：回应 reviewer 的质疑

> “如果 kinsn 本质上就是 kfunc + KF_INLINE_EMIT + emit callback，那第 3 节把它包装成独立 bytecode abstraction / extended ISA 就显得过度陈述。kinsn 相对已有 kfunc，到底多了什么不可替代的新能力？”

## 0. 先给结论

基于当前代码树，`kinsn` 不能被准确描述成“普通 kfunc 加一个 inline emit 回调”。  
它和普通 `kfunc` 的本质差异在于：

1. **语义源不同**：普通 `kfunc` 的 verifier 语义来自“BTF 原型 + flags”，函数体是黑盒；`kinsn` 的 verifier 语义来自 `instantiate_insn()` 生成的 ordinary-BPF proof sequence，verifier 真正逐条验证这段 proof sequence，而不是把它当黑盒 call。  
   代码证据：`vendor/linux-framework/include/linux/bpf.h:968-979`，`vendor/linux-framework/kernel/bpf/verifier.c:3669-3835`，`vendor/linux-framework/kernel/bpf/verifier.c:26408-26484`。

2. **抽象层级不同**：普通 `kfunc` 仍然是“函数调用”；`kinsn` 是“指令形式”的 transport。daemon 发出的不是 `BPF_PSEUDO_KFUNC_CALL`，而是“`sidecar + BPF_PSEUDO_KINSN_CALL`”这一对专用 bytecode 形式，payload 直接携带结果寄存器、输入寄存器、offset 等操作数字段。  
   代码证据：`daemon/src/insn.rs:243-290`，`vendor/linux-framework/include/linux/bpf.h:996-1007`，`vendor/linux-framework/kernel/bpf/verifier.c:21355-21476`。

3. **执行路径不同**：普通 `kfunc` 在 JIT 里被解析为真正的 runtime function call；`kinsn` 在 JIT 里根本不走函数地址调用，而是直接根据 descriptor + payload 发 native code。  
   代码证据：普通 `kfunc` 路径 `vendor/linux-framework/kernel/bpf/verifier.c:3542-3566` 与 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2477-2499`；`kinsn` 路径 `vendor/linux-framework/kernel/bpf/verifier.c:3524-3541`、`vendor/linux-framework/kernel/bpf/verifier.c:3882-3910`、`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:579-606`、`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2477-2483`。

4. **降级路径不同**：普通 `kfunc` 缺失时，调用点不可成立；BpfReJIT 的 `kinsn` pass 在 module/BTF 不可发现时直接不改写原程序，程序照常跑原始 eBPF；即便改写后缺少 native emit，kernel 也能回退到 proof sequence。  
   代码证据：`daemon/src/kfunc_discovery.rs:352-381`，`daemon/src/passes/rotate.rs:29-56`，`daemon/src/passes/cond_select.rs:143-171`，`vendor/linux-framework/kernel/bpf/verifier.c:23755-23795`。

因此，**复用 kfunc 注册/发现基础设施，只是 plumbing reuse；并不把 kinsn 降格成“普通 kfunc 的语义子集”**。  
真正独立存在的是三件东西：`sidecar` transport、proof-lowering verifier path、native emit dispatch。

---

## 1. 一个必须先纠正的前提：当前树里没有 `bpf_kinsn_effect / model_call`

题目背景里提到的 `bpf_kinsn_ops` / `bpf_kinsn_effect` / `model_call()`，**不是当前 in-tree 实现**。

当前 `include/linux/bpf.h` 里真正存在的是：

```c
struct bpf_kinsn {
	struct module *owner;
	u16 max_insn_cnt;
	u16 max_emit_bytes;
	int (*instantiate_insn)(u64 payload, struct bpf_insn *insn_buf);
	int (*emit_x86)(u8 *image, u32 *off, bool emit, u64 payload, const struct bpf_prog *prog);
	int (*emit_arm64)(u32 *image, int *idx, bool emit, u64 payload, const struct bpf_prog *prog);
};
```

代码证据：`vendor/linux-framework/include/linux/bpf.h:968-979`。  
设计文档也明确写了：**“There is no active `model_call()` or `bpf_kinsn_effect` path in the current tree.”**  
证据：`docs/kinsn-design.md:103-109`。

这意味着：

- 当前 tree 中，`kinsn` 的 verifier 语义不是 declarative effect DSL。
- 当前 tree 中，`kinsn` 的 verifier 语义来源是 `instantiate_insn()` 生成的 ordinary-BPF proof sequence。
- 因此，下面的 novelty 论证必须以 **proof-lowering model** 为准，而不能再按旧版 effect DSL 叙述。

这点很重要，因为 reviewer 如果按当前代码审读，你在正文里继续强调 `bpf_kinsn_effect`，会立刻被抓住“实现与论证不一致”。

---

## 2. 一张总表：普通 kfunc 与当前 kinsn 的真正差异

| 维度 | 普通 kfunc | 当前 kinsn |
| --- | --- | --- |
| 注册入口 | `register_btf_kfunc_id_set()` | 也复用 `register_btf_kfunc_id_set()`，但额外挂接 `kinsn_descs` |
| bytecode 编码 | `BPF_PSEUDO_KFUNC_CALL` | `sidecar + BPF_PSEUDO_KINSN_CALL` |
| verifier 看到什么 | call 指令；按 BTF prototype / flags 做参数与返回值建模 | 先被 lower 成 ordinary-BPF proof sequence，再跑标准 verifier |
| 语义源 | BTF 原型 + flags；函数体黑盒 | `instantiate_insn()` 生成的 proof sequence |
| JIT 执行 | 真实 `call` 到 kernel function 地址 | 直接 `emit_x86/emit_arm64` 内联发码 |
| 是否需要函数地址 | 需要：`kallsyms_lookup_name()` | 不需要：只需要 descriptor + payload |
| 操作数传递 | 走 R1-R5 调用 ABI，返回值在 R0 | payload 里直接携带 dst/src/off 等字段 |
| module 缺失时 | 调用点不可成立 | daemon 直接不改写原程序；已改写但无 native emit 时还能回退 proof sequence |
| 是否仍是“函数调用”抽象 | 是 | 否，已经是专用 instruction form |

对应代码：

- 复用注册入口但额外挂接 `kinsn_descs`：`vendor/linux-framework/include/linux/btf.h:122-127`，`vendor/linux-framework/kernel/bpf/btf.c:8784-8816`。
- 普通 `kfunc` 查到的是 `addr + func_model`：`vendor/linux-framework/kernel/bpf/verifier.c:3542-3566`。
- `kinsn` 查到的是 `desc->kinsn` 而不是函数地址：`vendor/linux-framework/kernel/bpf/verifier.c:3524-3541`。
- 普通 call bytecode 与 kinsn bytecode 区分：`daemon/src/insn.rs:223-255`。
- sidecar payload 编码：`daemon/src/insn.rs:277-290`，`vendor/linux-framework/include/linux/bpf.h:996-1007`。

---

## 3. “用 kfunc infra 实现”只是 plumbing reuse，不是语义等价

### 3.1 共享的是注册表，不是 verifier/JIT 语义

`kinsn` 的确复用了 kfunc 注册基础设施：

- `struct btf_kfunc_id_set` 多了 `const struct bpf_kinsn * const *kinsn_descs;`  
  证据：`vendor/linux-framework/include/linux/btf.h:122-127`
- 注册时，`btf_populate_kfunc_set()` 把 `(btf_id -> kinsn desc)` 填入独立的 `kinsn_sets`  
  证据：`vendor/linux-framework/kernel/bpf/btf.c:8784-8816`
- 查询时，`btf_kfunc_kinsn_desc()` 从这个附加表里取 descriptor  
  证据：`vendor/linux-framework/kernel/bpf/btf.c:8987-9005`

但是从 verifier 开始，普通 `kfunc` 与 `kinsn` 立即分叉：

- 普通 `kfunc` 分支：查 symbol 地址、蒸馏 `btf_func_model`、最终发出 runtime call  
  证据：`vendor/linux-framework/kernel/bpf/verifier.c:3542-3566`
- `kinsn` 分支：要求 `instantiate_insn != NULL`，保存 `desc->kinsn`，完全不取函数地址  
  证据：`vendor/linux-framework/kernel/bpf/verifier.c:3524-3541`

因此，**“用 kfunc infra 实现”只能推出 registration path 被复用，不能推出 semantic abstraction 没有新东西**。

### 3.2 如果将来统一到 kfunc 路径，也不等于 kinsn 不需要独立存在

即使把 `PSEUDO_KINSN_CALL` 统一编码到 `PSEUDO_KFUNC_CALL`，只要下面三样还在，`kinsn` 仍是独立抽象：

1. sidecar payload transport
2. proof-lowering verifier path
3. native emit dispatch

换句话说，**可以统一 plumbing，但不能消掉 abstraction**。  
消掉这三样之后，剩下的才只是“普通 kfunc 调用”。

---

## 4. verifier 本质差异：普通 kfunc 是黑盒 call，kinsn 是 proof-visible instruction

## 4.1 普通 kfunc：verifier 不看函数体，只看原型/flags

普通 `kfunc` 的元数据来自：

- BTF function prototype
- kfunc flags
- 允许性检查

证据：

- `fetch_kfunc_meta()` 从 BTF 取 `func_proto`、`func_name`、`kfunc_flags`：`vendor/linux-framework/kernel/bpf/verifier.c:3405-3449`
- `fetch_kfunc_arg_meta()` 只把 `btf/proto/name/flags` 填入 `meta`：`vendor/linux-framework/kernel/bpf/verifier.c:14203-14226`
- `check_kfunc_args()` 逐个参数按 BTF 类型做检查：`vendor/linux-framework/kernel/bpf/verifier.c:13656-14120`
- 返回值按 BTF 返回类型建模：`vendor/linux-framework/kernel/bpf/verifier.c:14650-14779`
- 调用后统一 clobber caller-saved regs：`vendor/linux-framework/kernel/bpf/verifier.c:14643-14648`

普通 `kfunc` descriptor 里保存的是：

```c
struct bpf_kfunc_desc {
	struct btf_func_model func_model;
	const struct bpf_kinsn *kinsn;
	u32 func_id;
	s32 imm;
	u16 offset;
	unsigned long addr;
};
```

证据：`vendor/linux-framework/kernel/bpf/verifier.c:3180-3187`。

对普通 `kfunc`，最终被填充的是 `addr` 和 `func_model`，而不是 `kinsn`：

- `addr = kallsyms_lookup_name(kfunc.name)`  
- `btf_distill_func_proto(..., &func_model)`  
- `desc->addr = addr; desc->func_model = func_model;`

证据：`vendor/linux-framework/kernel/bpf/verifier.c:3542-3566`，`vendor/linux-framework/kernel/bpf/btf.c:7485-7553`。

这说明普通 `kfunc` 的 verifier 视角始终是：“这是一个黑盒函数调用；我只知道签名，不知道函数体。”

## 4.2 kinsn：verifier 真正验证的是 instantiated proof sequence

`kinsn` 走的是完全不同的路径：

1. `add_subprog_and_kfunc()` 识别 `BPF_PSEUDO_KINSN_CALL`，统计 `env->kinsn_call_cnt`，并以 `kinsn_call=true` 注册 descriptor。  
   证据：`vendor/linux-framework/kernel/bpf/verifier.c:3928-3963`

2. `lower_kinsn_proof_regions()` 在主 verifier 之前，把每个 `sidecar + kinsn_call` 替换成 `instantiate_insn(payload)` 生成的 proof sequence。  
   证据：`vendor/linux-framework/kernel/bpf/verifier.c:3723-3835`

3. verifier 随后对 lowered 程序跑标准流程：`check_subprogs()`、`check_cfg()`、`compute_postorder()`、`compute_scc()`、`compute_live_registers()`、`do_check_main()`、`do_check_subprogs()`。  
   证据：`vendor/linux-framework/kernel/bpf/verifier.c:26408-26484`

4. 验证成功后，再 `restore_kinsn_proof_regions()` 把 proof sequence 恢复回原始 sidecar+call transport。  
   证据：`vendor/linux-framework/kernel/bpf/verifier.c:3837-3879`，`vendor/linux-framework/kernel/bpf/verifier.c:26479-26484`

还要注意两条非常强的证据：

- verifier 明确禁止“未 lowering 的 kinsn call”继续走普通 call 检查：  
  `internal error: kinsn call reached verifier without proof lowering`  
  证据：`vendor/linux-framework/kernel/bpf/verifier.c:21474-21476`

- `check_kinsn_sidecar_insn()` 只做 transport 完整性检查，要求 sidecar 后面必须立刻跟 kinsn call。  
  证据：`vendor/linux-framework/kernel/bpf/verifier.c:21355-21372`

所以，**当前 tree 中 kinsn 的 verifier 语义来源不是 call rule，而是 proof-lowering 后的 ordinary BPF**。  
这已经足以把它和普通 `kfunc` 区分开。

## 4.3 这比“普通 kfunc + emit callback”多了什么？

多出来的是：**call 站点不再被 verifier 当作 opaque function invocation，而被当作一个可以展开、验证、恢复的 instruction-form object。**

这正是 reviewer 质疑中的关键误区。  
如果只是“普通 kfunc + emit callback”，verifier 侧仍然会停留在 `check_kfunc_call()` 这条黑盒语义路径上。  
当前 `kinsn` 不是这样；它有一整条独立的 proof-lowering verifier path。

## 4.4 需要诚实加上的一个 caveat

如果按你最初的 `bpf_kinsn_effect` 说法，结论会更强：module 只能声明 effect，core verifier 强制执行 effect。  
**但这不是当前 tree 的实现。**

当前 tree 的真实安全叙述应更精确地写成：

- **BPF-visible safety** 来自 ordinary-BPF proof sequence 的标准 verifier；
- **native correctness** 额外依赖 `emit_x86/emit_arm64` 对 `instantiate_insn()` 的 refinement。

也就是说，当前 tree 确实比普通 `kfunc` 更“可验证”，但它的 novelty 是 **proof-visible instruction semantics**，不是更强的 **effect-DSL trust narrowing**。

---

## 5. 抽象层级差异：函数调用 vs 指令形式

## 5.1 普通 kfunc 仍然是 call ABI

普通 BPF call 的 helper/kfunc 原型是固定走寄存器 ABI 的：`func(u64 r1, u64 r2, u64 r3, u64 r4, u64 r5)`。  
证据：`vendor/linux-framework/include/linux/bpf.h:924-965`。

如果把一个局部 peephole 重写成普通 `kfunc`，即便语义上可行，也仍然要承担：

- 参数搬运到 R1-R5
- runtime `call` / `ret`
- 返回值从 R0 再搬回目标寄存器
- caller-saved clobber 语义

这仍然是**函数级**抽象。

## 5.2 kinsn transport 是专用 instruction form

daemon 发出的 kinsn 不是普通 call，而是：

1. `BpfInsn::kinsn_sidecar(payload)`
2. `BpfInsn::call_kinsn_with_off(btf_id, off)`

证据：`daemon/src/passes/utils.rs:281-292`，`daemon/src/insn.rs:243-290`。

payload 直接编码：

- 结果寄存器
- 输入寄存器
- offset
- 立即数参数

因此，**operand/result placement 是 payload-level，而不是 ABI-level**。

`emit_packed_kinsn_call_with_off()` 的注释甚至明确写了：

> “The result register is part of `payload`, so no extra `mov dst, r0` is emitted here.”

证据：`daemon/src/passes/utils.rs:281-292`。

这就是为什么它是 instruction abstraction，而不是 function abstraction。

## 5.3 具体 pass 里，替换粒度就是 instruction-form 粒度

### rotate

- 识别的是 `MOV provenance + RSH + LSH + OR` 窗口  
  证据：`daemon/src/passes/rotate.rs:239-360`
- `old_len = (pc + 3) - mov_pc`，即典型 4→2 BPF transport 替换  
  证据：`daemon/src/passes/rotate.rs:294-309`
- native emit 不是函数调用，而是 x86 `mov + rol` 或 ARM64 `EXTR`  
  证据：`module/x86/bpf_rotate.c:95-125`，`module/arm64/bpf_rotate.c:68-95`

### cond_select

- 识别 4-insn diamond 或 3-insn short pattern  
  证据：`daemon/src/passes/cond_select.rs:327-411`
- `old_len` 分别为 4 或 3  
  证据：`daemon/src/passes/cond_select.rs:361`，`daemon/src/passes/cond_select.rs:411`
- native emit 是 x86 `test + cmov` 或 ARM64 `tst + csel`  
  证据：`module/x86/bpf_select.c:102-146`，`module/arm64/bpf_select.c:71-105`

### extract

- 识别 `RSH + AND` 两条指令  
  证据：`daemon/src/passes/extract.rs:55-94`
- `old_len = 2`，替换成 2-insn transport  
  证据：`daemon/src/passes/extract.rs:77-83`，`daemon/src/passes/extract.rs:196-200`
- native emit 是直接内联 bitfield extract sequence，而不是 helper body call  
  证据：`module/x86/bpf_extract.c:96-127`，`module/arm64/bpf_extract.c:64-90`

### endian_fusion

- 识别 `LDX_MEM + ENDIAN_TO_BE`  
  证据：`daemon/src/passes/endian.rs:17-33`，`daemon/src/passes/endian.rs:53-107`
- 直接把 offset 编进 payload；必要时也只是在 packed transport 周围补地址物化，而不是切回 legacy call ABI  
  证据：`daemon/src/passes/endian.rs:155-210`
- 注释明确说“instead of using any legacy call ABI”  
  证据：`daemon/src/passes/endian.rs:30-33`

### bulk_memory

- 识别大段 scalarized memcpy/memset  
  证据：`daemon/src/passes/bulk_memory.rs:92-93`
- `MIN_BULK_BYTES = 32`，`CHUNK_MAX_BYTES = 128`  
  证据：`daemon/src/passes/bulk_memory.rs:12-18`
- 每个 chunk 仅发出 `2` 条 transport 指令  
  证据：`daemon/src/passes/bulk_memory.rs:529-547`，`daemon/src/passes/bulk_memory.rs:557-573`
- verifier proof sequence 却可以展开为最多 `128*2` 条 bytewise memcpy 指令  
  证据：`module/x86/bpf_bulk_memory.c:131-150`，`module/x86/bpf_bulk_memory.c:449-455`

这类“**大窗口 -> 单个逻辑指令 -> 小 native 序列**”的替换，正是普通 `kfunc` 难以等价替代的地方。

---

## 6. 优雅降级：这也是普通 kfunc 不具备的产品级属性

## 6.1 module 没加载时，daemon 直接保持原始 bytecode

discovery 阶段如果 `/sys/kernel/btf/<module>` 不存在，就把该 target 标成 unavailable：

- `module '<name>' not loaded (no BTF at ...)`
- 对应 `registry.*_btf_id` 保持 `-1`

证据：`daemon/src/kfunc_discovery.rs:311-381`。

各 pass 在发现 target 不可用时，直接 `changed=false` 返回，不改原程序：

- rotate：`daemon/src/passes/rotate.rs:29-41`
- cond_select：`daemon/src/passes/cond_select.rs:143-171`
- extract：`daemon/src/passes/extract.rs:111-138`
- endian_fusion：`daemon/src/passes/endian.rs:228-266`
- bulk_memory：`daemon/src/passes/bulk_memory.rs:151-175`

这意味着 **module 缺失不会导致应用程序不能运行，只会让优化 pass 不生效**。

## 6.2 module 存在但当前架构/后端没有 native emit 时，kernel 回退到 proof sequence

在 `do_misc_fixups()` 里：

- 若 `prog->jit_requested && bpf_kinsn_has_native_emit(kinsn)`，保留 sidecar+call 给 JIT 原生发码；
- 否则，就把 sidecar+call 替换成 `instantiate_insn()` 生成的 proof sequence。

证据：`vendor/linux-framework/kernel/bpf/verifier.c:23755-23795`。

所以 kinsn 有两层 graceful degradation：

1. **用户态 pass 层**：没发现 module，就不改写
2. **内核 JIT 层**：发现了 kinsn 但没 native emit，也还能退回 ordinary BPF

这比“硬依赖某个 kfunc 必须存在，否则 load fail”更平滑。

---

## 7. “纯用 kfunc 能不能做出同样效果？”答案是：不能等价复制当前实现的关键性质

## 7.1 代码已经表明这些 pass 依赖的是 packed kinsn，而不是普通 kfunc

当前真正使用 `emit_packed_kinsn_call_with_off()` 的 pass 一共有 5 个：

1. `bulk_memory`
2. `rotate`
3. `cond_select`
4. `extract`
5. `endian_fusion`

证据：

- `daemon/src/passes/bulk_memory.rs`
- `daemon/src/passes/rotate.rs`
- `daemon/src/passes/cond_select.rs`
- `daemon/src/passes/extract.rs`
- `daemon/src/passes/endian.rs`

这些 pass 发出的都是 `BPF_PSEUDO_KINSN_CALL`，不是 `BPF_PSEUDO_KFUNC_CALL`。  
证据：`daemon/src/passes/utils.rs:281-292`，以及各 pass 的 replacement 构造代码。

## 7.2 某些 pass 明确拒绝回退到 legacy call ABI

最清楚的是 `endian_fusion` 和 `cond_select`：

- `endian_fusion` 注释明确说，即便 offset 不能直接编码，也是在 packed transport 周围补地址计算，**“instead of using any legacy call ABI”**。  
  证据：`daemon/src/passes/endian.rs:30-33`

- `cond_select` 如果 true/false 不是寄存器值，就直接 skip，原因是 packed path 需要 register operands；它没有实现任何“普通 kfunc ABI fallback”。  
  证据：`daemon/src/passes/cond_select.rs:104-111`，`daemon/src/passes/cond_select.rs:227-233`

这不是偶然，而是实现者明确在说：**纯 kfunc ABI 不是这个抽象想要的东西。**

## 7.3 普通 kfunc 只能给你“call 一个函数”，而不是“在 bytecode 中保留一个 instruction site”

如果没有 `kinsn`，你最多能做到：

- 把 peephole pattern 改写成普通 `kfunc` 调用；
- 希望 JIT 再特殊识别这个 call 去做 inline emit。

但这样依然缺 3 个核心能力：

1. verifier 不会把它当 proof-visible instruction，只会走黑盒 call rule；
2. bytecode 中没有独立的 sidecar payload instruction form；
3. daemon 无法在不占用 R1-R5 ABI 的情况下，把 dst/src/off 等局部语义原样保留到后端。

换言之，**没有 kinsn，你可以伪装出“可 inline 的函数调用”；但你得不到“可验证、可恢复、可携带 operand payload 的指令形式”。**

---

## 8. 量化：当前仓库里到底有多少优化依赖 kinsn？

`PASS_REGISTRY` 一共注册了 12 个 pass：  
证据：`daemon/src/passes/mod.rs:52-118`

其中 **5 个直接依赖 kinsn packed transport**：

1. `bulk_memory`
2. `rotate`
3. `cond_select`
4. `extract`
5. `endian_fusion`

其余 **7 个是纯 bytecode 变换，不依赖 kinsn**：

1. `map_inline`
2. `const_prop`
3. `dce`
4. `skb_load_bytes_spec`
5. `bounds_check_merge`
6. `wide_mem`
7. `branch_flip`

特别是 `wide_mem` 的注释写得很直白：

> “No kinsn support needed -- pure BPF replacement.”

证据：`daemon/src/passes/wide_mem.rs:380-385`。

因此，从现有实现看：

- **kinsn 不是整个系统的必要条件**；
- 但它确实支撑了一组独立的、不可用纯 bytecode pass 替代的指令级 peephole 优化；
- reviewer 如果问 “到底多了什么新能力”，答案不是“所有优化都靠 kinsn”，而是“**某一类 instruction-form peephole optimization 需要它**”。

## 8.1 静态替换规模

| pass | 典型原始窗口 | BPF transport | native emit |
| --- | --- | --- | --- |
| rotate | 4 insns | 2 insns | x86 `mov+rol` / ARM64 `EXTR` |
| cond_select | 3 或 4 insns | 2 insns | x86 `test+cmov` / ARM64 `tst+csel` |
| extract | 2 insns | 2 insns | x86 inline extract seq / ARM64 `UBFM` |
| endian_fusion | 2 insns | 2 insns（少数场景 3-4） | x86 load+bswap / ARM64 load+REV |
| bulk_memory | 32B~128B 的长 store/load run | 每 chunk 2 insns | x86 `rep movsb/stosb` 或 ARM64 pair-loop |

这张表的重点不是所有 case 都是“N→1 machine insn”，而是：

- `kinsn` 把局部优化机会保留成一个独立的 instruction site；
- JIT 再把它降为短 native 序列；
- 中间没有普通函数调用 ABI 的寄存器搬运与 runtime call。

---

## 9. 给 reviewer 的直接回答

可以把回应压缩成下面这段：

> `kinsn` 复用了 `kfunc` 的注册与发现 plumbing，但它不是普通 `kfunc` 的语义别名。普通 `kfunc` 在 verifier 中是黑盒函数调用，安全模型只基于 BTF prototype 和 flags；当前 `kinsn` 则在主 verifier 之前被 lower 成 ordinary-BPF proof sequence，verifier 真正验证的是这段展开后的 BPF 语义，然后再把 site 恢复成原始 `sidecar + PSEUDO_KINSN_CALL` transport。JIT 阶段，普通 `kfunc` 仍是 runtime call 到 kernel symbol，而 `kinsn` 则根据 payload 直接内联 native code。因此，`kinsn` 的 novelty 不在于“又发明了一条注册 API”，而在于它把目标相关 peephole 优化提升成一种 verifier-visible、bytecode-carried、可原生发码又可回退 proof sequence 的 instruction-form abstraction。没有 kinsn，最多只能得到一个可 inline 的函数调用；得不到当前这种带 sidecar payload、proof-lowering、native emit dispatch 的独立指令抽象。`

---

## 10. 对论文措辞的建议

基于当前代码树，建议正文避免再使用下面这些说法：

- “`bpf_kinsn_effect` 是当前实现”
- “module 只声明 effect，core verifier 强制执行 effect”
- “当前 in-tree novelty 主要来自 declarative effect DSL”

更准确的表述应该是：

1. **当前实现的 novelty**：proof-visible instruction form + packed sidecar transport + native emit refinement + graceful degradation。
2. **不是 novelty 的部分**：kfunc registration plumbing 复用。
3. **如果想讨论 effect DSL**：应明确写成 future design / stronger design point，而不是 current implementation。

否则 reviewer 很容易抓住“文字说的是 effect DSL，代码实现其实是 proof-lowering”这一点。

---

## 11. 最终判断

如果严格基于当前代码树，我的结论是：

- **“kinsn 只是 kfunc + emit callback”这个说法不成立。**
- 但 **“kinsn 的 novelty 来自 declarative effect DSL”这个说法在当前 tree 也不成立。**

当前 tree 能站得住脚的 novelty，是：

1. **专用 bytecode transport**：`sidecar + PSEUDO_KINSN_CALL`
2. **独立 verifier 语义**：proof-lowering，而非黑盒 call
3. **独立 JIT 语义**：descriptor-driven native inline emit，而非 runtime symbol call
4. **双层 graceful degradation**：daemon 不改写 / kernel proof fallback

如果第 3 节按这个版本重写，reviewer 的质疑可以被正面化解；  
如果继续把当前实现写成 `bpf_kinsn_effect` 式的 effect DSL，就会留下明显的可攻击点。

codex
文档主体已经落盘，当前在检查后半部分的表格、pass 统计和 reviewer 回应段，确认论证都对齐到实际实现。
exec
/bin/bash -lc "sed -n '261,520p' /home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/kinsn_vs_kfunc_novelty_20260328.md" in /home/yunwei37/workspace/bpf-benchmark
 succeeded in 0ms:
- `old_len = (pc + 3) - mov_pc`，即典型 4→2 BPF transport 替换  
  证据：`daemon/src/passes/rotate.rs:294-309`
- native emit 不是函数调用，而是 x86 `mov + rol` 或 ARM64 `EXTR`  
  证据：`module/x86/bpf_rotate.c:95-125`，`module/arm64/bpf_rotate.c:68-95`

### cond_select

- 识别 4-insn diamond 或 3-insn short pattern  
  证据：`daemon/src/passes/cond_select.rs:327-411`
- `old_len` 分别为 4 或 3  
  证据：`daemon/src/passes/cond_select.rs:361`，`daemon/src/passes/cond_select.rs:411`
- native emit 是 x86 `test + cmov` 或 ARM64 `tst + csel`  
  证据：`module/x86/bpf_select.c:102-146`，`module/arm64/bpf_select.c:71-105`

### extract

- 识别 `RSH + AND` 两条指令  
  证据：`daemon/src/passes/extract.rs:55-94`
- `old_len = 2`，替换成 2-insn transport  
  证据：`daemon/src/passes/extract.rs:77-83`，`daemon/src/passes/extract.rs:196-200`
- native emit 是直接内联 bitfield extract sequence，而不是 helper body call  
  证据：`module/x86/bpf_extract.c:96-127`，`module/arm64/bpf_extract.c:64-90`

### endian_fusion

- 识别 `LDX_MEM + ENDIAN_TO_BE`  
  证据：`daemon/src/passes/endian.rs:17-33`，`daemon/src/passes/endian.rs:53-107`
- 直接把 offset 编进 payload；必要时也只是在 packed transport 周围补地址物化，而不是切回 legacy call ABI  
  证据：`daemon/src/passes/endian.rs:155-210`
- 注释明确说“instead of using any legacy call ABI”  
  证据：`daemon/src/passes/endian.rs:30-33`

### bulk_memory

- 识别大段 scalarized memcpy/memset  
  证据：`daemon/src/passes/bulk_memory.rs:92-93`
- `MIN_BULK_BYTES = 32`，`CHUNK_MAX_BYTES = 128`  
  证据：`daemon/src/passes/bulk_memory.rs:12-18`
- 每个 chunk 仅发出 `2` 条 transport 指令  
  证据：`daemon/src/passes/bulk_memory.rs:529-547`，`daemon/src/passes/bulk_memory.rs:557-573`
- verifier proof sequence 却可以展开为最多 `128*2` 条 bytewise memcpy 指令  
  证据：`module/x86/bpf_bulk_memory.c:131-150`，`module/x86/bpf_bulk_memory.c:449-455`

这类“**大窗口 -> 单个逻辑指令 -> 小 native 序列**”的替换，正是普通 `kfunc` 难以等价替代的地方。

---

## 6. 优雅降级：这也是普通 kfunc 不具备的产品级属性

## 6.1 module 没加载时，daemon 直接保持原始 bytecode

discovery 阶段如果 `/sys/kernel/btf/<module>` 不存在，就把该 target 标成 unavailable：

- `module '<name>' not loaded (no BTF at ...)`
- 对应 `registry.*_btf_id` 保持 `-1`

证据：`daemon/src/kfunc_discovery.rs:311-381`。

各 pass 在发现 target 不可用时，直接 `changed=false` 返回，不改原程序：

- rotate：`daemon/src/passes/rotate.rs:29-41`
- cond_select：`daemon/src/passes/cond_select.rs:143-171`
- extract：`daemon/src/passes/extract.rs:111-138`
- endian_fusion：`daemon/src/passes/endian.rs:228-266`
- bulk_memory：`daemon/src/passes/bulk_memory.rs:151-175`

这意味着 **module 缺失不会导致应用程序不能运行，只会让优化 pass 不生效**。

## 6.2 module 存在但当前架构/后端没有 native emit 时，kernel 回退到 proof sequence

在 `do_misc_fixups()` 里：

- 若 `prog->jit_requested && bpf_kinsn_has_native_emit(kinsn)`，保留 sidecar+call 给 JIT 原生发码；
- 否则，就把 sidecar+call 替换成 `instantiate_insn()` 生成的 proof sequence。

证据：`vendor/linux-framework/kernel/bpf/verifier.c:23755-23795`。

所以 kinsn 有两层 graceful degradation：

1. **用户态 pass 层**：没发现 module，就不改写
2. **内核 JIT 层**：发现了 kinsn 但没 native emit，也还能退回 ordinary BPF

这比“硬依赖某个 kfunc 必须存在，否则 load fail”更平滑。

---

## 7. “纯用 kfunc 能不能做出同样效果？”答案是：不能等价复制当前实现的关键性质

## 7.1 代码已经表明这些 pass 依赖的是 packed kinsn，而不是普通 kfunc

当前真正使用 `emit_packed_kinsn_call_with_off()` 的 pass 一共有 5 个：

1. `bulk_memory`
2. `rotate`
3. `cond_select`
4. `extract`
5. `endian_fusion`

证据：

- `daemon/src/passes/bulk_memory.rs`
- `daemon/src/passes/rotate.rs`
- `daemon/src/passes/cond_select.rs`
- `daemon/src/passes/extract.rs`
- `daemon/src/passes/endian.rs`

这些 pass 发出的都是 `BPF_PSEUDO_KINSN_CALL`，不是 `BPF_PSEUDO_KFUNC_CALL`。  
证据：`daemon/src/passes/utils.rs:281-292`，以及各 pass 的 replacement 构造代码。

## 7.2 某些 pass 明确拒绝回退到 legacy call ABI

最清楚的是 `endian_fusion` 和 `cond_select`：

- `endian_fusion` 注释明确说，即便 offset 不能直接编码，也是在 packed transport 周围补地址计算，**“instead of using any legacy call ABI”**。  
  证据：`daemon/src/passes/endian.rs:30-33`

- `cond_select` 如果 true/false 不是寄存器值，就直接 skip，原因是 packed path 需要 register operands；它没有实现任何“普通 kfunc ABI fallback”。  
  证据：`daemon/src/passes/cond_select.rs:104-111`，`daemon/src/passes/cond_select.rs:227-233`

这不是偶然，而是实现者明确在说：**纯 kfunc ABI 不是这个抽象想要的东西。**

## 7.3 普通 kfunc 只能给你“call 一个函数”，而不是“在 bytecode 中保留一个 instruction site”

如果没有 `kinsn`，你最多能做到：

- 把 peephole pattern 改写成普通 `kfunc` 调用；
- 希望 JIT 再特殊识别这个 call 去做 inline emit。

但这样依然缺 3 个核心能力：

1. verifier 不会把它当 proof-visible instruction，只会走黑盒 call rule；
2. bytecode 中没有独立的 sidecar payload instruction form；
3. daemon 无法在不占用 R1-R5 ABI 的情况下，把 dst/src/off 等局部语义原样保留到后端。

换言之，**没有 kinsn，你可以伪装出“可 inline 的函数调用”；但你得不到“可验证、可恢复、可携带 operand payload 的指令形式”。**

---

## 8. 量化：当前仓库里到底有多少优化依赖 kinsn？

`PASS_REGISTRY` 一共注册了 12 个 pass：  
证据：`daemon/src/passes/mod.rs:52-118`

其中 **5 个直接依赖 kinsn packed transport**：

1. `bulk_memory`
2. `rotate`
3. `cond_select`
4. `extract`
5. `endian_fusion`

其余 **7 个是纯 bytecode 变换，不依赖 kinsn**：

1. `map_inline`
2. `const_prop`
3. `dce`
4. `skb_load_bytes_spec`
5. `bounds_check_merge`
6. `wide_mem`
7. `branch_flip`

特别是 `wide_mem` 的注释写得很直白：

> “No kinsn support needed -- pure BPF replacement.”

证据：`daemon/src/passes/wide_mem.rs:380-385`。

因此，从现有实现看：

- **kinsn 不是整个系统的必要条件**；
- 但它确实支撑了一组独立的、不可用纯 bytecode pass 替代的指令级 peephole 优化；
- reviewer 如果问 “到底多了什么新能力”，答案不是“所有优化都靠 kinsn”，而是“**某一类 instruction-form peephole optimization 需要它**”。

## 8.1 静态替换规模

| pass | 典型原始窗口 | BPF transport | native emit |
| --- | --- | --- | --- |
| rotate | 4 insns | 2 insns | x86 `mov+rol` / ARM64 `EXTR` |
| cond_select | 3 或 4 insns | 2 insns | x86 `test+cmov` / ARM64 `tst+csel` |
| extract | 2 insns | 2 insns | x86 inline extract seq / ARM64 `UBFM` |
| endian_fusion | 2 insns | 2 insns（少数场景 3-4） | x86 load+bswap / ARM64 load+REV |
| bulk_memory | 32B~128B 的长 store/load run | 每 chunk 2 insns | x86 `rep movsb/stosb` 或 ARM64 pair-loop |

这张表的重点不是所有 case 都是“N→1 machine insn”，而是：

- `kinsn` 把局部优化机会保留成一个独立的 instruction site；
- JIT 再把它降为短 native 序列；
- 中间没有普通函数调用 ABI 的寄存器搬运与 runtime call。

---

## 9. 给 reviewer 的直接回答

可以把回应压缩成下面这段：

> `kinsn` 复用了 `kfunc` 的注册与发现 plumbing，但它不是普通 `kfunc` 的语义别名。普通 `kfunc` 在 verifier 中是黑盒函数调用，安全模型只基于 BTF prototype 和 flags；当前 `kinsn` 则在主 verifier 之前被 lower 成 ordinary-BPF proof sequence，verifier 真正验证的是这段展开后的 BPF 语义，然后再把 site 恢复成原始 `sidecar + PSEUDO_KINSN_CALL` transport。JIT 阶段，普通 `kfunc` 仍是 runtime call 到 kernel symbol，而 `kinsn` 则根据 payload 直接内联 native code。因此，`kinsn` 的 novelty 不在于“又发明了一条注册 API”，而在于它把目标相关 peephole 优化提升成一种 verifier-visible、bytecode-carried、可原生发码又可回退 proof sequence 的 instruction-form abstraction。没有 kinsn，最多只能得到一个可 inline 的函数调用；得不到当前这种带 sidecar payload、proof-lowering、native emit dispatch 的独立指令抽象。`

---

## 10. 对论文措辞的建议

基于当前代码树，建议正文避免再使用下面这些说法：

- “`bpf_kinsn_effect` 是当前实现”
- “module 只声明 effect，core verifier 强制执行 effect”
- “当前 in-tree novelty 主要来自 declarative effect DSL”

更准确的表述应该是：

1. **当前实现的 novelty**：proof-visible instruction form + packed sidecar transport + native emit refinement + graceful degradation。
2. **不是 novelty 的部分**：kfunc registration plumbing 复用。
3. **如果想讨论 effect DSL**：应明确写成 future design / stronger design point，而不是 current implementation。

否则 reviewer 很容易抓住“文字说的是 effect DSL，代码实现其实是 proof-lowering”这一点。

---

## 11. 最终判断

如果严格基于当前代码树，我的结论是：

- **“kinsn 只是 kfunc + emit callback”这个说法不成立。**
- 但 **“kinsn 的 novelty 来自 declarative effect DSL”这个说法在当前 tree 也不成立。**

当前 tree 能站得住脚的 novelty，是：

1. **专用 bytecode transport**：`sidecar + PSEUDO_KINSN_CALL`
2. **独立 verifier 语义**：proof-lowering，而非黑盒 call
3. **独立 JIT 语义**：descriptor-driven native inline emit，而非 runtime symbol call
4. **双层 graceful degradation**：daemon 不改写 / kernel proof fallback

如果第 3 节按这个版本重写，reviewer 的质疑可以被正面化解；  
如果继续把当前实现写成 `bpf_kinsn_effect` 式的 effect DSL，就会留下明显的可攻击点。

diff --git a/docs/tmp/20260328/kinsn_vs_kfunc_novelty_20260328.md b/docs/tmp/20260328/kinsn_vs_kfunc_novelty_20260328.md
new file mode 100644
index 0000000000000000000000000000000000000000..f65466f4f3326c56196ecf1fa0829f5f1c240e23
--- /dev/null
++ b/docs/tmp/20260328/kinsn_vs_kfunc_novelty_20260328.md
@@ -0,0 +1,493 @@
# kinsn vs kfunc：本质差异与 novelty 论证

日期：2026-03-28  
目标：回应 reviewer 的质疑

> “如果 kinsn 本质上就是 kfunc + KF_INLINE_EMIT + emit callback，那第 3 节把它包装成独立 bytecode abstraction / extended ISA 就显得过度陈述。kinsn 相对已有 kfunc，到底多了什么不可替代的新能力？”

## 0. 先给结论

基于当前代码树，`kinsn` 不能被准确描述成“普通 kfunc 加一个 inline emit 回调”。  
它和普通 `kfunc` 的本质差异在于：

1. **语义源不同**：普通 `kfunc` 的 verifier 语义来自“BTF 原型 + flags”，函数体是黑盒；`kinsn` 的 verifier 语义来自 `instantiate_insn()` 生成的 ordinary-BPF proof sequence，verifier 真正逐条验证这段 proof sequence，而不是把它当黑盒 call。  
   代码证据：`vendor/linux-framework/include/linux/bpf.h:968-979`，`vendor/linux-framework/kernel/bpf/verifier.c:3669-3835`，`vendor/linux-framework/kernel/bpf/verifier.c:26408-26484`。

2. **抽象层级不同**：普通 `kfunc` 仍然是“函数调用”；`kinsn` 是“指令形式”的 transport。daemon 发出的不是 `BPF_PSEUDO_KFUNC_CALL`，而是“`sidecar + BPF_PSEUDO_KINSN_CALL`”这一对专用 bytecode 形式，payload 直接携带结果寄存器、输入寄存器、offset 等操作数字段。  
   代码证据：`daemon/src/insn.rs:243-290`，`vendor/linux-framework/include/linux/bpf.h:996-1007`，`vendor/linux-framework/kernel/bpf/verifier.c:21355-21476`。

3. **执行路径不同**：普通 `kfunc` 在 JIT 里被解析为真正的 runtime function call；`kinsn` 在 JIT 里根本不走函数地址调用，而是直接根据 descriptor + payload 发 native code。  
   代码证据：普通 `kfunc` 路径 `vendor/linux-framework/kernel/bpf/verifier.c:3542-3566` 与 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2477-2499`；`kinsn` 路径 `vendor/linux-framework/kernel/bpf/verifier.c:3524-3541`、`vendor/linux-framework/kernel/bpf/verifier.c:3882-3910`、`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:579-606`、`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2477-2483`。

4. **降级路径不同**：普通 `kfunc` 缺失时，调用点不可成立；BpfReJIT 的 `kinsn` pass 在 module/BTF 不可发现时直接不改写原程序，程序照常跑原始 eBPF；即便改写后缺少 native emit，kernel 也能回退到 proof sequence。  
   代码证据：`daemon/src/kfunc_discovery.rs:352-381`，`daemon/src/passes/rotate.rs:29-56`，`daemon/src/passes/cond_select.rs:143-171`，`vendor/linux-framework/kernel/bpf/verifier.c:23755-23795`。

因此，**复用 kfunc 注册/发现基础设施，只是 plumbing reuse；并不把 kinsn 降格成“普通 kfunc 的语义子集”**。  
真正独立存在的是三件东西：`sidecar` transport、proof-lowering verifier path、native emit dispatch。

---

## 1. 一个必须先纠正的前提：当前树里没有 `bpf_kinsn_effect / model_call`

题目背景里提到的 `bpf_kinsn_ops` / `bpf_kinsn_effect` / `model_call()`，**不是当前 in-tree 实现**。

当前 `include/linux/bpf.h` 里真正存在的是：

```c
struct bpf_kinsn {
	struct module *owner;
	u16 max_insn_cnt;
	u16 max_emit_bytes;
	int (*instantiate_insn)(u64 payload, struct bpf_insn *insn_buf);
	int (*emit_x86)(u8 *image, u32 *off, bool emit, u64 payload, const struct bpf_prog *prog);
	int (*emit_arm64)(u32 *image, int *idx, bool emit, u64 payload, const struct bpf_prog *prog);
};
```

代码证据：`vendor/linux-framework/include/linux/bpf.h:968-979`。  
设计文档也明确写了：**“There is no active `model_call()` or `bpf_kinsn_effect` path in the current tree.”**  
证据：`docs/kinsn-design.md:103-109`。

这意味着：

- 当前 tree 中，`kinsn` 的 verifier 语义不是 declarative effect DSL。
- 当前 tree 中，`kinsn` 的 verifier 语义来源是 `instantiate_insn()` 生成的 ordinary-BPF proof sequence。
- 因此，下面的 novelty 论证必须以 **proof-lowering model** 为准，而不能再按旧版 effect DSL 叙述。

这点很重要，因为 reviewer 如果按当前代码审读，你在正文里继续强调 `bpf_kinsn_effect`，会立刻被抓住“实现与论证不一致”。

---

## 2. 一张总表：普通 kfunc 与当前 kinsn 的真正差异

| 维度 | 普通 kfunc | 当前 kinsn |
| --- | --- | --- |
| 注册入口 | `register_btf_kfunc_id_set()` | 也复用 `register_btf_kfunc_id_set()`，但额外挂接 `kinsn_descs` |
| bytecode 编码 | `BPF_PSEUDO_KFUNC_CALL` | `sidecar + BPF_PSEUDO_KINSN_CALL` |
| verifier 看到什么 | call 指令；按 BTF prototype / flags 做参数与返回值建模 | 先被 lower 成 ordinary-BPF proof sequence，再跑标准 verifier |
| 语义源 | BTF 原型 + flags；函数体黑盒 | `instantiate_insn()` 生成的 proof sequence |
| JIT 执行 | 真实 `call` 到 kernel function 地址 | 直接 `emit_x86/emit_arm64` 内联发码 |
| 是否需要函数地址 | 需要：`kallsyms_lookup_name()` | 不需要：只需要 descriptor + payload |
| 操作数传递 | 走 R1-R5 调用 ABI，返回值在 R0 | payload 里直接携带 dst/src/off 等字段 |
| module 缺失时 | 调用点不可成立 | daemon 直接不改写原程序；已改写但无 native emit 时还能回退 proof sequence |
| 是否仍是“函数调用”抽象 | 是 | 否，已经是专用 instruction form |

对应代码：

- 复用注册入口但额外挂接 `kinsn_descs`：`vendor/linux-framework/include/linux/btf.h:122-127`，`vendor/linux-framework/kernel/bpf/btf.c:8784-8816`。
- 普通 `kfunc` 查到的是 `addr + func_model`：`vendor/linux-framework/kernel/bpf/verifier.c:3542-3566`。
- `kinsn` 查到的是 `desc->kinsn` 而不是函数地址：`vendor/linux-framework/kernel/bpf/verifier.c:3524-3541`。
- 普通 call bytecode 与 kinsn bytecode 区分：`daemon/src/insn.rs:223-255`。
- sidecar payload 编码：`daemon/src/insn.rs:277-290`，`vendor/linux-framework/include/linux/bpf.h:996-1007`。

---

## 3. “用 kfunc infra 实现”只是 plumbing reuse，不是语义等价

### 3.1 共享的是注册表，不是 verifier/JIT 语义

`kinsn` 的确复用了 kfunc 注册基础设施：

- `struct btf_kfunc_id_set` 多了 `const struct bpf_kinsn * const *kinsn_descs;`  
  证据：`vendor/linux-framework/include/linux/btf.h:122-127`
- 注册时，`btf_populate_kfunc_set()` 把 `(btf_id -> kinsn desc)` 填入独立的 `kinsn_sets`  
  证据：`vendor/linux-framework/kernel/bpf/btf.c:8784-8816`
- 查询时，`btf_kfunc_kinsn_desc()` 从这个附加表里取 descriptor  
  证据：`vendor/linux-framework/kernel/bpf/btf.c:8987-9005`

但是从 verifier 开始，普通 `kfunc` 与 `kinsn` 立即分叉：

- 普通 `kfunc` 分支：查 symbol 地址、蒸馏 `btf_func_model`、最终发出 runtime call  
  证据：`vendor/linux-framework/kernel/bpf/verifier.c:3542-3566`
- `kinsn` 分支：要求 `instantiate_insn != NULL`，保存 `desc->kinsn`，完全不取函数地址  
  证据：`vendor/linux-framework/kernel/bpf/verifier.c:3524-3541`

因此，**“用 kfunc infra 实现”只能推出 registration path 被复用，不能推出 semantic abstraction 没有新东西**。

### 3.2 如果将来统一到 kfunc 路径，也不等于 kinsn 不需要独立存在

即使把 `PSEUDO_KINSN_CALL` 统一编码到 `PSEUDO_KFUNC_CALL`，只要下面三样还在，`kinsn` 仍是独立抽象：

1. sidecar payload transport
2. proof-lowering verifier path
3. native emit dispatch

换句话说，**可以统一 plumbing，但不能消掉 abstraction**。  
消掉这三样之后，剩下的才只是“普通 kfunc 调用”。

---

## 4. verifier 本质差异：普通 kfunc 是黑盒 call，kinsn 是 proof-visible instruction

## 4.1 普通 kfunc：verifier 不看函数体，只看原型/flags

普通 `kfunc` 的元数据来自：

- BTF function prototype
- kfunc flags
- 允许性检查

证据：

- `fetch_kfunc_meta()` 从 BTF 取 `func_proto`、`func_name`、`kfunc_flags`：`vendor/linux-framework/kernel/bpf/verifier.c:3405-3449`
- `fetch_kfunc_arg_meta()` 只把 `btf/proto/name/flags` 填入 `meta`：`vendor/linux-framework/kernel/bpf/verifier.c:14203-14226`
- `check_kfunc_args()` 逐个参数按 BTF 类型做检查：`vendor/linux-framework/kernel/bpf/verifier.c:13656-14120`
- 返回值按 BTF 返回类型建模：`vendor/linux-framework/kernel/bpf/verifier.c:14650-14779`
- 调用后统一 clobber caller-saved regs：`vendor/linux-framework/kernel/bpf/verifier.c:14643-14648`

普通 `kfunc` descriptor 里保存的是：

```c
struct bpf_kfunc_desc {
	struct btf_func_model func_model;
	const struct bpf_kinsn *kinsn;
	u32 func_id;
	s32 imm;
	u16 offset;
	unsigned long addr;
};
```

证据：`vendor/linux-framework/kernel/bpf/verifier.c:3180-3187`。

对普通 `kfunc`，最终被填充的是 `addr` 和 `func_model`，而不是 `kinsn`：

- `addr = kallsyms_lookup_name(kfunc.name)`  
- `btf_distill_func_proto(..., &func_model)`  
- `desc->addr = addr; desc->func_model = func_model;`

证据：`vendor/linux-framework/kernel/bpf/verifier.c:3542-3566`，`vendor/linux-framework/kernel/bpf/btf.c:7485-7553`。

这说明普通 `kfunc` 的 verifier 视角始终是：“这是一个黑盒函数调用；我只知道签名，不知道函数体。”

## 4.2 kinsn：verifier 真正验证的是 instantiated proof sequence

`kinsn` 走的是完全不同的路径：

1. `add_subprog_and_kfunc()` 识别 `BPF_PSEUDO_KINSN_CALL`，统计 `env->kinsn_call_cnt`，并以 `kinsn_call=true` 注册 descriptor。  
   证据：`vendor/linux-framework/kernel/bpf/verifier.c:3928-3963`

2. `lower_kinsn_proof_regions()` 在主 verifier 之前，把每个 `sidecar + kinsn_call` 替换成 `instantiate_insn(payload)` 生成的 proof sequence。  
   证据：`vendor/linux-framework/kernel/bpf/verifier.c:3723-3835`

3. verifier 随后对 lowered 程序跑标准流程：`check_subprogs()`、`check_cfg()`、`compute_postorder()`、`compute_scc()`、`compute_live_registers()`、`do_check_main()`、`do_check_subprogs()`。  
   证据：`vendor/linux-framework/kernel/bpf/verifier.c:26408-26484`

4. 验证成功后，再 `restore_kinsn_proof_regions()` 把 proof sequence 恢复回原始 sidecar+call transport。  
   证据：`vendor/linux-framework/kernel/bpf/verifier.c:3837-3879`，`vendor/linux-framework/kernel/bpf/verifier.c:26479-26484`

还要注意两条非常强的证据：

- verifier 明确禁止“未 lowering 的 kinsn call”继续走普通 call 检查：  
  `internal error: kinsn call reached verifier without proof lowering`  
  证据：`vendor/linux-framework/kernel/bpf/verifier.c:21474-21476`

- `check_kinsn_sidecar_insn()` 只做 transport 完整性检查，要求 sidecar 后面必须立刻跟 kinsn call。  
  证据：`vendor/linux-framework/kernel/bpf/verifier.c:21355-21372`

所以，**当前 tree 中 kinsn 的 verifier 语义来源不是 call rule，而是 proof-lowering 后的 ordinary BPF**。  
这已经足以把它和普通 `kfunc` 区分开。

## 4.3 这比“普通 kfunc + emit callback”多了什么？

多出来的是：**call 站点不再被 verifier 当作 opaque function invocation，而被当作一个可以展开、验证、恢复的 instruction-form object。**

这正是 reviewer 质疑中的关键误区。  
如果只是“普通 kfunc + emit callback”，verifier 侧仍然会停留在 `check_kfunc_call()` 这条黑盒语义路径上。  
当前 `kinsn` 不是这样；它有一整条独立的 proof-lowering verifier path。

## 4.4 需要诚实加上的一个 caveat

如果按你最初的 `bpf_kinsn_effect` 说法，结论会更强：module 只能声明 effect，core verifier 强制执行 effect。  
**但这不是当前 tree 的实现。**

当前 tree 的真实安全叙述应更精确地写成：

- **BPF-visible safety** 来自 ordinary-BPF proof sequence 的标准 verifier；
- **native correctness** 额外依赖 `emit_x86/emit_arm64` 对 `instantiate_insn()` 的 refinement。

也就是说，当前 tree 确实比普通 `kfunc` 更“可验证”，但它的 novelty 是 **proof-visible instruction semantics**，不是更强的 **effect-DSL trust narrowing**。

---

## 5. 抽象层级差异：函数调用 vs 指令形式

## 5.1 普通 kfunc 仍然是 call ABI

普通 BPF call 的 helper/kfunc 原型是固定走寄存器 ABI 的：`func(u64 r1, u64 r2, u64 r3, u64 r4, u64 r5)`。  
证据：`vendor/linux-framework/include/linux/bpf.h:924-965`。

如果把一个局部 peephole 重写成普通 `kfunc`，即便语义上可行，也仍然要承担：

- 参数搬运到 R1-R5
- runtime `call` / `ret`
- 返回值从 R0 再搬回目标寄存器
- caller-saved clobber 语义

这仍然是**函数级**抽象。

## 5.2 kinsn transport 是专用 instruction form

daemon 发出的 kinsn 不是普通 call，而是：

1. `BpfInsn::kinsn_sidecar(payload)`
2. `BpfInsn::call_kinsn_with_off(btf_id, off)`

证据：`daemon/src/passes/utils.rs:281-292`，`daemon/src/insn.rs:243-290`。

payload 直接编码：

- 结果寄存器
- 输入寄存器
- offset
- 立即数参数

因此，**operand/result placement 是 payload-level，而不是 ABI-level**。

`emit_packed_kinsn_call_with_off()` 的注释甚至明确写了：

> “The result register is part of `payload`, so no extra `mov dst, r0` is emitted here.”

证据：`daemon/src/passes/utils.rs:281-292`。

这就是为什么它是 instruction abstraction，而不是 function abstraction。

## 5.3 具体 pass 里，替换粒度就是 instruction-form 粒度

### rotate

- 识别的是 `MOV provenance + RSH + LSH + OR` 窗口  
  证据：`daemon/src/passes/rotate.rs:239-360`
- `old_len = (pc + 3) - mov_pc`，即典型 4→2 BPF transport 替换  
  证据：`daemon/src/passes/rotate.rs:294-309`
- native emit 不是函数调用，而是 x86 `mov + rol` 或 ARM64 `EXTR`  
  证据：`module/x86/bpf_rotate.c:95-125`，`module/arm64/bpf_rotate.c:68-95`

### cond_select

- 识别 4-insn diamond 或 3-insn short pattern  
  证据：`daemon/src/passes/cond_select.rs:327-411`
- `old_len` 分别为 4 或 3  
  证据：`daemon/src/passes/cond_select.rs:361`，`daemon/src/passes/cond_select.rs:411`
- native emit 是 x86 `test + cmov` 或 ARM64 `tst + csel`  
  证据：`module/x86/bpf_select.c:102-146`，`module/arm64/bpf_select.c:71-105`

### extract

- 识别 `RSH + AND` 两条指令  
  证据：`daemon/src/passes/extract.rs:55-94`
- `old_len = 2`，替换成 2-insn transport  
  证据：`daemon/src/passes/extract.rs:77-83`，`daemon/src/passes/extract.rs:196-200`
- native emit 是直接内联 bitfield extract sequence，而不是 helper body call  
  证据：`module/x86/bpf_extract.c:96-127`，`module/arm64/bpf_extract.c:64-90`

### endian_fusion

- 识别 `LDX_MEM + ENDIAN_TO_BE`  
  证据：`daemon/src/passes/endian.rs:17-33`，`daemon/src/passes/endian.rs:53-107`
- 直接把 offset 编进 payload；必要时也只是在 packed transport 周围补地址物化，而不是切回 legacy call ABI  
  证据：`daemon/src/passes/endian.rs:155-210`
- 注释明确说“instead of using any legacy call ABI”  
  证据：`daemon/src/passes/endian.rs:30-33`

### bulk_memory

- 识别大段 scalarized memcpy/memset  
  证据：`daemon/src/passes/bulk_memory.rs:92-93`
- `MIN_BULK_BYTES = 32`，`CHUNK_MAX_BYTES = 128`  
  证据：`daemon/src/passes/bulk_memory.rs:12-18`
- 每个 chunk 仅发出 `2` 条 transport 指令  
  证据：`daemon/src/passes/bulk_memory.rs:529-547`，`daemon/src/passes/bulk_memory.rs:557-573`
- verifier proof sequence 却可以展开为最多 `128*2` 条 bytewise memcpy 指令  
  证据：`module/x86/bpf_bulk_memory.c:131-150`，`module/x86/bpf_bulk_memory.c:449-455`

这类“**大窗口 -> 单个逻辑指令 -> 小 native 序列**”的替换，正是普通 `kfunc` 难以等价替代的地方。

---

## 6. 优雅降级：这也是普通 kfunc 不具备的产品级属性

## 6.1 module 没加载时，daemon 直接保持原始 bytecode

discovery 阶段如果 `/sys/kernel/btf/<module>` 不存在，就把该 target 标成 unavailable：

- `module '<name>' not loaded (no BTF at ...)`
- 对应 `registry.*_btf_id` 保持 `-1`

证据：`daemon/src/kfunc_discovery.rs:311-381`。

各 pass 在发现 target 不可用时，直接 `changed=false` 返回，不改原程序：

- rotate：`daemon/src/passes/rotate.rs:29-41`
- cond_select：`daemon/src/passes/cond_select.rs:143-171`
- extract：`daemon/src/passes/extract.rs:111-138`
- endian_fusion：`daemon/src/passes/endian.rs:228-266`
- bulk_memory：`daemon/src/passes/bulk_memory.rs:151-175`

这意味着 **module 缺失不会导致应用程序不能运行，只会让优化 pass 不生效**。

## 6.2 module 存在但当前架构/后端没有 native emit 时，kernel 回退到 proof sequence

在 `do_misc_fixups()` 里：

- 若 `prog->jit_requested && bpf_kinsn_has_native_emit(kinsn)`，保留 sidecar+call 给 JIT 原生发码；
- 否则，就把 sidecar+call 替换成 `instantiate_insn()` 生成的 proof sequence。

证据：`vendor/linux-framework/kernel/bpf/verifier.c:23755-23795`。

所以 kinsn 有两层 graceful degradation：

1. **用户态 pass 层**：没发现 module，就不改写
2. **内核 JIT 层**：发现了 kinsn 但没 native emit，也还能退回 ordinary BPF

这比“硬依赖某个 kfunc 必须存在，否则 load fail”更平滑。

---

## 7. “纯用 kfunc 能不能做出同样效果？”答案是：不能等价复制当前实现的关键性质

## 7.1 代码已经表明这些 pass 依赖的是 packed kinsn，而不是普通 kfunc

当前真正使用 `emit_packed_kinsn_call_with_off()` 的 pass 一共有 5 个：

1. `bulk_memory`
2. `rotate`
3. `cond_select`
4. `extract`
5. `endian_fusion`

证据：

- `daemon/src/passes/bulk_memory.rs`
- `daemon/src/passes/rotate.rs`
- `daemon/src/passes/cond_select.rs`
- `daemon/src/passes/extract.rs`
- `daemon/src/passes/endian.rs`

这些 pass 发出的都是 `BPF_PSEUDO_KINSN_CALL`，不是 `BPF_PSEUDO_KFUNC_CALL`。  
证据：`daemon/src/passes/utils.rs:281-292`，以及各 pass 的 replacement 构造代码。

## 7.2 某些 pass 明确拒绝回退到 legacy call ABI

最清楚的是 `endian_fusion` 和 `cond_select`：

- `endian_fusion` 注释明确说，即便 offset 不能直接编码，也是在 packed transport 周围补地址计算，**“instead of using any legacy call ABI”**。  
  证据：`daemon/src/passes/endian.rs:30-33`

- `cond_select` 如果 true/false 不是寄存器值，就直接 skip，原因是 packed path 需要 register operands；它没有实现任何“普通 kfunc ABI fallback”。  
  证据：`daemon/src/passes/cond_select.rs:104-111`，`daemon/src/passes/cond_select.rs:227-233`

这不是偶然，而是实现者明确在说：**纯 kfunc ABI 不是这个抽象想要的东西。**

## 7.3 普通 kfunc 只能给你“call 一个函数”，而不是“在 bytecode 中保留一个 instruction site”

如果没有 `kinsn`，你最多能做到：

- 把 peephole pattern 改写成普通 `kfunc` 调用；
- 希望 JIT 再特殊识别这个 call 去做 inline emit。

但这样依然缺 3 个核心能力：

1. verifier 不会把它当 proof-visible instruction，只会走黑盒 call rule；
2. bytecode 中没有独立的 sidecar payload instruction form；
3. daemon 无法在不占用 R1-R5 ABI 的情况下，把 dst/src/off 等局部语义原样保留到后端。

换言之，**没有 kinsn，你可以伪装出“可 inline 的函数调用”；但你得不到“可验证、可恢复、可携带 operand payload 的指令形式”。**

---

## 8. 量化：当前仓库里到底有多少优化依赖 kinsn？

`PASS_REGISTRY` 一共注册了 12 个 pass：  
证据：`daemon/src/passes/mod.rs:52-118`

其中 **5 个直接依赖 kinsn packed transport**：

1. `bulk_memory`
2. `rotate`
3. `cond_select`
4. `extract`
5. `endian_fusion`

其余 **7 个是纯 bytecode 变换，不依赖 kinsn**：

1. `map_inline`
2. `const_prop`
3. `dce`
4. `skb_load_bytes_spec`
5. `bounds_check_merge`
6. `wide_mem`
7. `branch_flip`

特别是 `wide_mem` 的注释写得很直白：

> “No kinsn support needed -- pure BPF replacement.”

证据：`daemon/src/passes/wide_mem.rs:380-385`。

因此，从现有实现看：

- **kinsn 不是整个系统的必要条件**；
- 但它确实支撑了一组独立的、不可用纯 bytecode pass 替代的指令级 peephole 优化；
- reviewer 如果问 “到底多了什么新能力”，答案不是“所有优化都靠 kinsn”，而是“**某一类 instruction-form peephole optimization 需要它**”。

## 8.1 静态替换规模

| pass | 典型原始窗口 | BPF transport | native emit |
| --- | --- | --- | --- |
| rotate | 4 insns | 2 insns | x86 `mov+rol` / ARM64 `EXTR` |
| cond_select | 3 或 4 insns | 2 insns | x86 `test+cmov` / ARM64 `tst+csel` |
| extract | 2 insns | 2 insns | x86 inline extract seq / ARM64 `UBFM` |
| endian_fusion | 2 insns | 2 insns（少数场景 3-4） | x86 load+bswap / ARM64 load+REV |
| bulk_memory | 32B~128B 的长 store/load run | 每 chunk 2 insns | x86 `rep movsb/stosb` 或 ARM64 pair-loop |

这张表的重点不是所有 case 都是“N→1 machine insn”，而是：

- `kinsn` 把局部优化机会保留成一个独立的 instruction site；
- JIT 再把它降为短 native 序列；
- 中间没有普通函数调用 ABI 的寄存器搬运与 runtime call。

---

## 9. 给 reviewer 的直接回答

可以把回应压缩成下面这段：

> `kinsn` 复用了 `kfunc` 的注册与发现 plumbing，但它不是普通 `kfunc` 的语义别名。普通 `kfunc` 在 verifier 中是黑盒函数调用，安全模型只基于 BTF prototype 和 flags；当前 `kinsn` 则在主 verifier 之前被 lower 成 ordinary-BPF proof sequence，verifier 真正验证的是这段展开后的 BPF 语义，然后再把 site 恢复成原始 `sidecar + PSEUDO_KINSN_CALL` transport。JIT 阶段，普通 `kfunc` 仍是 runtime call 到 kernel symbol，而 `kinsn` 则根据 payload 直接内联 native code。因此，`kinsn` 的 novelty 不在于“又发明了一条注册 API”，而在于它把目标相关 peephole 优化提升成一种 verifier-visible、bytecode-carried、可原生发码又可回退 proof sequence 的 instruction-form abstraction。没有 kinsn，最多只能得到一个可 inline 的函数调用；得不到当前这种带 sidecar payload、proof-lowering、native emit dispatch 的独立指令抽象。`

---

## 10. 对论文措辞的建议

基于当前代码树，建议正文避免再使用下面这些说法：

- “`bpf_kinsn_effect` 是当前实现”
- “module 只声明 effect，core verifier 强制执行 effect”
- “当前 in-tree novelty 主要来自 declarative effect DSL”

更准确的表述应该是：

1. **当前实现的 novelty**：proof-visible instruction form + packed sidecar transport + native emit refinement + graceful degradation。
2. **不是 novelty 的部分**：kfunc registration plumbing 复用。
3. **如果想讨论 effect DSL**：应明确写成 future design / stronger design point，而不是 current implementation。

否则 reviewer 很容易抓住“文字说的是 effect DSL，代码实现其实是 proof-lowering”这一点。

---

## 11. 最终判断

如果严格基于当前代码树，我的结论是：

- **“kinsn 只是 kfunc + emit callback”这个说法不成立。**
- 但 **“kinsn 的 novelty 来自 declarative effect DSL”这个说法在当前 tree 也不成立。**

当前 tree 能站得住脚的 novelty，是：

1. **专用 bytecode transport**：`sidecar + PSEUDO_KINSN_CALL`
2. **独立 verifier 语义**：proof-lowering，而非黑盒 call
3. **独立 JIT 语义**：descriptor-driven native inline emit，而非 runtime symbol call
4. **双层 graceful degradation**：daemon 不改写 / kernel proof fallback

如果第 3 节按这个版本重写，reviewer 的质疑可以被正面化解；  
如果继续把当前实现写成 `bpf_kinsn_effect` 式的 effect DSL，就会留下明显的可攻击点。

codex
我在抽查关键锚点的行号，重点核对 `instantiate_insn`、`check_kfunc_call`、`sidecar + PSEUDO_KINSN_CALL` 和 daemon 的 packed transport，避免文档里的引用偏行。
exec
/bin/bash -lc 'rg -n "struct bpf_kinsn|bpf_kinsn_has_native_emit|bpf_kinsn_sidecar_payload|struct bpf_func_proto|struct btf_func_model|bpf_jit_find_kfunc_model|bpf_jit_get_kinsn_payload" /home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/include/linux/bpf.h' in /home/yunwei37/workspace/bpf-benchmark
 succeeded in 0ms:
924:struct bpf_func_proto {
968:struct bpf_kinsn {
981:static inline bool bpf_kinsn_has_native_emit(const struct bpf_kinsn *kinsn)
1002:static inline u64 bpf_kinsn_sidecar_payload(const struct bpf_insn *insn)
1141:	const struct bpf_func_proto *
1209:struct btf_func_model {
1306:				const struct btf_func_model *m, u32 flags,
1312:int arch_bpf_trampoline_size(const struct btf_func_model *m, u32 flags,
1386:		struct btf_func_model model;
1404:	struct btf_func_model fmodel;
2054:	struct btf_func_model func_models[BPF_STRUCT_OPS_MAX_NR_MEMBERS];
2150:				      const struct btf_func_model *model,
2383:const struct bpf_func_proto *bpf_get_trace_printk_proto(void);
2384:const struct bpf_func_proto *bpf_get_trace_vprintk_proto(void);
2386:const struct bpf_func_proto *bpf_get_perf_event_read_value_proto(void);
2897:typedef const struct bpf_func_proto *
2935:const struct bpf_func_proto *
3073:			   struct btf_func_model *m);
3087:const struct bpf_func_proto *bpf_base_func_proto(enum bpf_func_id func_id,
3092:const struct btf_func_model *
3093:bpf_jit_find_kfunc_model(const struct bpf_prog *prog,
3095:int bpf_jit_get_kinsn_payload(const struct bpf_prog *prog,
3097:			      const struct bpf_kinsn **kinsn,
3368:static inline const struct bpf_func_proto *
3383:static inline const struct btf_func_model *
3384:bpf_jit_find_kfunc_model(const struct bpf_prog *prog,
3391:bpf_jit_get_kinsn_payload(const struct bpf_prog *prog,
3393:			      const struct bpf_kinsn **kinsn,
3721:extern const struct bpf_func_proto bpf_map_lookup_elem_proto;
3722:extern const struct bpf_func_proto bpf_map_update_elem_proto;
3723:extern const struct bpf_func_proto bpf_map_delete_elem_proto;
3724:extern const struct bpf_func_proto bpf_map_push_elem_proto;
3725:extern const struct bpf_func_proto bpf_map_pop_elem_proto;
3726:extern const struct bpf_func_proto bpf_map_peek_elem_proto;
3727:extern const struct bpf_func_proto bpf_map_lookup_percpu_elem_proto;
3729:extern const struct bpf_func_proto bpf_get_prandom_u32_proto;
3730:extern const struct bpf_func_proto bpf_get_smp_processor_id_proto;
3731:extern const struct bpf_func_proto bpf_get_numa_node_id_proto;
3732:extern const struct bpf_func_proto bpf_tail_call_proto;
3733:extern const struct bpf_func_proto bpf_ktime_get_ns_proto;
3734:extern const struct bpf_func_proto bpf_ktime_get_boot_ns_proto;
3735:extern const struct bpf_func_proto bpf_ktime_get_tai_ns_proto;
3736:extern const struct bpf_func_proto bpf_get_current_pid_tgid_proto;
3737:extern const struct bpf_func_proto bpf_get_current_uid_gid_proto;
3738:extern const struct bpf_func_proto bpf_get_current_comm_proto;
3739:extern const struct bpf_func_proto bpf_get_stackid_proto;
3740:extern const struct bpf_func_proto bpf_get_stack_proto;
3741:extern const struct bpf_func_proto bpf_get_stack_sleepable_proto;
3742:extern const struct bpf_func_proto bpf_get_task_stack_proto;
3743:extern const struct bpf_func_proto bpf_get_task_stack_sleepable_proto;
3744:extern const struct bpf_func_proto bpf_get_stackid_proto_pe;
3745:extern const struct bpf_func_proto bpf_get_stack_proto_pe;
3746:extern const struct bpf_func_proto bpf_sock_map_update_proto;
3747:extern const struct bpf_func_proto bpf_sock_hash_update_proto;
3748:extern const struct bpf_func_proto bpf_get_current_cgroup_id_proto;
3749:extern const struct bpf_func_proto bpf_get_current_ancestor_cgroup_id_proto;
3750:extern const struct bpf_func_proto bpf_get_cgroup_classid_curr_proto;
3751:extern const struct bpf_func_proto bpf_current_task_under_cgroup_proto;
3752:extern const struct bpf_func_proto bpf_msg_redirect_hash_proto;
3753:extern const struct bpf_func_proto bpf_msg_redirect_map_proto;
3754:extern const struct bpf_func_proto bpf_sk_redirect_hash_proto;
3755:extern const struct bpf_func_proto bpf_sk_redirect_map_proto;
3756:extern const struct bpf_func_proto bpf_spin_lock_proto;
3757:extern const struct bpf_func_proto bpf_spin_unlock_proto;
3758:extern const struct bpf_func_proto bpf_get_local_storage_proto;
3759:extern const struct bpf_func_proto bpf_strtol_proto;
3760:extern const struct bpf_func_proto bpf_strtoul_proto;
3761:extern const struct bpf_func_proto bpf_tcp_sock_proto;
3762:extern const struct bpf_func_proto bpf_jiffies64_proto;
3763:extern const struct bpf_func_proto bpf_get_ns_current_pid_tgid_proto;
3764:extern const struct bpf_func_proto bpf_event_output_data_proto;
3765:extern const struct bpf_func_proto bpf_ringbuf_output_proto;
3766:extern const struct bpf_func_proto bpf_ringbuf_reserve_proto;
3767:extern const struct bpf_func_proto bpf_ringbuf_submit_proto;
3768:extern const struct bpf_func_proto bpf_ringbuf_discard_proto;
3769:extern const struct bpf_func_proto bpf_ringbuf_query_proto;
3770:extern const struct bpf_func_proto bpf_ringbuf_reserve_dynptr_proto;
3771:extern const struct bpf_func_proto bpf_ringbuf_submit_dynptr_proto;
3772:extern const struct bpf_func_proto bpf_ringbuf_discard_dynptr_proto;
3773:extern const struct bpf_func_proto bpf_skc_to_tcp6_sock_proto;
3774:extern const struct bpf_func_proto bpf_skc_to_tcp_sock_proto;
3775:extern const struct bpf_func_proto bpf_skc_to_tcp_timewait_sock_proto;
3776:extern const struct bpf_func_proto bpf_skc_to_tcp_request_sock_proto;
3777:extern const struct bpf_func_proto bpf_skc_to_udp6_sock_proto;
3778:extern const struct bpf_func_proto bpf_skc_to_unix_sock_proto;
3779:extern const struct bpf_func_proto bpf_skc_to_mptcp_sock_proto;
3780:extern const struct bpf_func_proto bpf_copy_from_user_proto;
3781:extern const struct bpf_func_proto bpf_snprintf_btf_proto;
3782:extern const struct bpf_func_proto bpf_snprintf_proto;
3783:extern const struct bpf_func_proto bpf_per_cpu_ptr_proto;
3784:extern const struct bpf_func_proto bpf_this_cpu_ptr_proto;
3785:extern const struct bpf_func_proto bpf_ktime_get_coarse_ns_proto;
3786:extern const struct bpf_func_proto bpf_sock_from_file_proto;
3787:extern const struct bpf_func_proto bpf_get_socket_ptr_cookie_proto;
3788:extern const struct bpf_func_proto bpf_task_storage_get_recur_proto;
3789:extern const struct bpf_func_proto bpf_task_storage_get_proto;
3790:extern const struct bpf_func_proto bpf_task_storage_delete_recur_proto;
3791:extern const struct bpf_func_proto bpf_task_storage_delete_proto;
3792:extern const struct bpf_func_proto bpf_for_each_map_elem_proto;
3793:extern const struct bpf_func_proto bpf_btf_find_by_name_kind_proto;
3794:extern const struct bpf_func_proto bpf_sk_setsockopt_proto;
3795:extern const struct bpf_func_proto bpf_sk_getsockopt_proto;
3796:extern const struct bpf_func_proto bpf_unlocked_sk_setsockopt_proto;
3797:extern const struct bpf_func_proto bpf_unlocked_sk_getsockopt_proto;
3798:extern const struct bpf_func_proto bpf_find_vma_proto;
3799:extern const struct bpf_func_proto bpf_loop_proto;
3800:extern const struct bpf_func_proto bpf_copy_from_user_task_proto;
3801:extern const struct bpf_func_proto bpf_set_retval_proto;
3802:extern const struct bpf_func_proto bpf_get_retval_proto;
3803:extern const struct bpf_func_proto bpf_user_ringbuf_drain_proto;
3804:extern const struct bpf_func_proto bpf_cgrp_storage_get_proto;
3805:extern const struct bpf_func_proto bpf_cgrp_storage_delete_proto;
3807:const struct bpf_func_proto *tracing_prog_func_proto(

exec
/bin/bash -lc 'rg -n "struct btf_kfunc_id_set|kinsn_descs" /home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/include/linux/btf.h' in /home/yunwei37/workspace/bpf-benchmark
 succeeded in 0ms:
122:struct btf_kfunc_id_set {
126:	const struct bpf_kinsn * const *kinsn_descs;
586:			      const struct btf_kfunc_id_set *s);
587:int register_btf_fmodret_id_set(const struct btf_kfunc_id_set *kset);
651:					    const struct btf_kfunc_id_set *s)

exec
/bin/bash -lc 'rg -n "fetch_kfunc_meta|add_kfunc_desc|validate_kinsn_proof_seq|lower_kinsn_proof_regions|restore_kinsn_proof_regions|bpf_jit_get_kinsn_payload|add_subprog_and_kfunc|check_kfunc_args|fetch_kfunc_arg_meta|check_kfunc_call|check_kinsn_sidecar_insn|internal error: kinsn call reached verifier without proof lowering|do_misc_fixups|do_check_main|do_check_subprogs" /home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/verifier.c' in /home/yunwei37/workspace/bpf-benchmark
exec
/bin/bash -lc "rg -n \"emit_kinsn_desc_call|emit_call\\(|PSEUDO_KINSN_CALL|sidecar\" /home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/x86/net/bpf_jit_comp.c" in /home/yunwei37/workspace/bpf-benchmark
 succeeded in 0ms:
416:static int emit_call(u8 **prog, void *func, void *ip);
426:		emit_call(&prog, __bhi_args[arity], ip + 11);
574:static int emit_call(u8 **pprog, void *func, void *ip)
579:static int emit_kinsn_desc_call(u8 **pprog, const struct bpf_prog *bpf_prog,
635:		      emit_call(&prog, old_addr, ip) :
645:		      emit_call(&prog, new_addr, ip) :
1655:		if (emit_call(&prog, func, ip))
1898:			if (bpf_kinsn_is_sidecar_insn(insn))
2478:			if (src_reg == BPF_PSEUDO_KINSN_CALL) {
2479:				err = emit_kinsn_desc_call(&prog, bpf_prog, insn,
2496:			if (emit_call(&prog, func, ip))

 succeeded in 0ms:
3198:	 * available, therefore at the end of verification do_misc_fixups()
3390:static int fetch_kfunc_meta(struct bpf_verifier_env *env,
3454:static int add_kfunc_desc(struct bpf_verifier_env *env, u32 func_id, s16 offset,
3517:	err = fetch_kfunc_meta(env, func_id, offset, &kfunc);
3669:static int validate_kinsn_proof_seq(struct bpf_verifier_env *env,
3723:static int lower_kinsn_proof_regions(struct bpf_verifier_env *env)
3771:		err = bpf_jit_get_kinsn_payload(env->prog, call, &kinsn, &payload);
3786:		err = validate_kinsn_proof_seq(env, kinsn, proof_buf, cnt);
3837:static int restore_kinsn_proof_regions(struct bpf_verifier_env *env)
3882:int bpf_jit_get_kinsn_payload(const struct bpf_prog *prog,
3920:			ret = add_kfunc_desc(env, insn->imm, insn->off, false);
3928:static int add_subprog_and_kfunc(struct bpf_verifier_env *env)
3955:			ret = add_kfunc_desc(env, insn->imm, insn->off, false);
3958:			ret = add_kfunc_desc(env, insn->imm, insn->off, true);
4074:	 * check_kfunc_call.
13656:static int check_kfunc_args(struct bpf_verifier_env *env, struct bpf_kfunc_call_arg_meta *meta,
14203:static int fetch_kfunc_arg_meta(struct bpf_verifier_env *env,
14211:	err = fetch_kfunc_meta(env, func_id, offset, &kfunc);
14411:static int check_kfunc_call(struct bpf_verifier_env *env, struct bpf_insn *insn,
14429:	err = fetch_kfunc_arg_meta(env, insn->imm, insn->off, &meta);
14486:	err = check_kfunc_args(env, &meta, insn_idx);
14899:	/* Corresponding fixup done in do_misc_fixups(). */
18612:/* True if do_misc_fixups() replaces calls to helper number 'imm',
18669:		err = fetch_kfunc_arg_meta(env, call->imm, call->off, &meta);
19177:			ret = fetch_kfunc_arg_meta(env, insn->imm, insn->off, &meta);
21355:static int check_kinsn_sidecar_insn(struct bpf_verifier_env *env,
21382:		return check_kinsn_sidecar_insn(env, insn);
21471:				err = check_kfunc_call(env, insn, &env->insn_idx);
21475:				verbose(env, "internal error: kinsn call reached verifier without proof lowering\n");
23720:static int do_misc_fixups(struct bpf_verifier_env *env)
23763:			ret = bpf_jit_get_kinsn_payload(env->prog, call, &kinsn, NULL);
23778:			ret = validate_kinsn_proof_seq(env, kinsn, env->insn_buf, cnt);
25091:static int do_check_subprogs(struct bpf_verifier_env *env)
25141:static int do_check_main(struct bpf_verifier_env *env)
26408:	ret = add_subprog_and_kfunc(env);
26412:	ret = lower_kinsn_proof_regions(env);
26473:	ret = do_check_main(env);
26474:	ret = ret ?: do_check_subprogs(env);
26484:		ret = restore_kinsn_proof_regions(env);
26516:		ret = do_misc_fixups(env);

exec
/bin/bash -lc "rg -n \"call_kfunc_with_off|call_kinsn_with_off|kinsn_sidecar|emit_packed_kinsn_call_with_off|module '.*' not loaded|PASS_REGISTRY|No kinsn support needed|instead of using any legacy call ABI|packed ABI should apply without save/restore|packed ABI should not depend on free callee-saved regs\" /home/yunwei37/workspace/bpf-benchmark/daemon/src" in /home/yunwei37/workspace/bpf-benchmark
 succeeded in 0ms:
/home/yunwei37/workspace/bpf-benchmark/daemon/src/insn.rs:228:    pub const fn call_kfunc_with_off(btf_id: i32, off: i16) -> Self {
/home/yunwei37/workspace/bpf-benchmark/daemon/src/insn.rs:240:        Self::call_kfunc_with_off(btf_id, 0)
/home/yunwei37/workspace/bpf-benchmark/daemon/src/insn.rs:248:    pub const fn call_kinsn_with_off(btf_id: i32, off: i16) -> Self {
/home/yunwei37/workspace/bpf-benchmark/daemon/src/insn.rs:279:    /// Payload layout matches `bpf_kinsn_sidecar_payload()` in the kernel:
/home/yunwei37/workspace/bpf-benchmark/daemon/src/insn.rs:283:    pub const fn kinsn_sidecar(payload: u64) -> Self {
/home/yunwei37/workspace/bpf-benchmark/daemon/src/insn.rs:333:    pub const fn is_kinsn_sidecar(&self) -> bool {
/home/yunwei37/workspace/bpf-benchmark/daemon/src/pass.rs:613:    crate::passes::PASS_REGISTRY
/home/yunwei37/workspace/bpf-benchmark/daemon/src/pass.rs:753:            .chain(crate::passes::PASS_REGISTRY.iter().map(|entry| entry.name))
/home/yunwei37/workspace/bpf-benchmark/daemon/src/kfunc_discovery.rs:356:                "  {}: module '{}' not loaded (no BTF at {})",
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/bulk_memory_tests.rs:106:    emit_packed_kinsn_call_with_off(
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/bulk_memory_tests.rs:114:    emit_packed_kinsn_call_with_off(
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/rotate.rs:8:use super::utils::{emit_packed_kinsn_call_with_off, ensure_btf_fd_slot, fixup_all_branches};
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/rotate.rs:160:                let replacement = emit_packed_kinsn_call_with_off(payload, btf_id, kfunc_off);
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/rotate.rs:584:            "packed ABI should apply without save/restore"
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/rotate.rs:618:            "packed ABI should not depend on free callee-saved regs"
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/bulk_memory.rs:10:use super::utils::{emit_packed_kinsn_call_with_off, ensure_btf_fd_slot, fixup_all_branches};
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/bulk_memory.rs:533:                out.extend_from_slice(&emit_packed_kinsn_call_with_off(
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/bulk_memory.rs:560:                out.extend_from_slice(&emit_packed_kinsn_call_with_off(
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/wide_mem.rs:384:/// of the kernel JIT surplus. No kinsn support needed -- pure BPF replacement.
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/endian.rs:8:use super::utils::{emit_packed_kinsn_call_with_off, ensure_btf_fd_slot, fixup_all_branches};
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/endian.rs:33:/// packed call instead of using any legacy call ABI.
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/endian.rs:176:        out.extend_from_slice(&emit_packed_kinsn_call_with_off(
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/endian.rs:190:        out.extend_from_slice(&emit_packed_kinsn_call_with_off(
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/endian.rs:205:    out.extend_from_slice(&emit_packed_kinsn_call_with_off(
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/endian.rs:650:        assert!(prog.insns[0].is_kinsn_sidecar());
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/endian.rs:672:        assert!(prog.insns[0].is_kinsn_sidecar());
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/endian.rs:695:            "packed ABI should apply without save/restore"
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/endian.rs:726:            "packed ABI should not depend on free callee-saved regs"
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/utils.rs:284:pub fn emit_packed_kinsn_call_with_off(
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/utils.rs:290:        BpfInsn::kinsn_sidecar(payload),
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/utils.rs:291:        BpfInsn::call_kinsn_with_off(kinsn_btf_id, kinsn_off),
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/utils.rs:423:        let insns = emit_packed_kinsn_call_with_off(payload, 1234, 2);
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/utils.rs:426:        assert!(insns[0].is_kinsn_sidecar());
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/utils.rs:438:        let insns = emit_packed_kinsn_call_with_off(payload, 5555, 0);
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/utils.rs:441:        assert!(insns[0].is_kinsn_sidecar());
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/extract.rs:8:use super::utils::{emit_packed_kinsn_call_with_off, ensure_btf_fd_slot, fixup_all_branches};
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/extract.rs:199:                let replacement = emit_packed_kinsn_call_with_off(payload, btf_id, kfunc_off);
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/extract.rs:473:            "packed ABI should apply without save/restore"
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/extract.rs:504:            "packed ABI should not depend on free callee-saved regs"
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/cond_select_tests.rs:421:        "packed ABI should apply without save/restore"
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/cond_select_tests.rs:449:        "packed ABI should not depend on free callee-saved regs"
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/cond_select_tests.rs:484:    assert!(prog.insns[0].is_kinsn_sidecar());
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/cond_select_tests.rs:519:    let sidecar = insns.iter().find(|insn| insn.is_kinsn_sidecar()).unwrap();
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/mod.rs:52:pub const PASS_REGISTRY: &[PassRegistryEntry] = &[
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/mod.rs:122:    PASS_REGISTRY
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/mod.rs:136:        let known = PASS_REGISTRY.iter().any(|entry| entry.name == *name);
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/mod.rs:147:    Ok(PASS_REGISTRY
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/mod.rs:165:/// Build the default optimization pipeline from `PASS_REGISTRY` in canonical order.
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/mod.rs:170:    for entry in PASS_REGISTRY {
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/mod.rs:179:/// Pass names are matched against `PASS_REGISTRY` entries by canonical name.
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/cond_select.rs:8:use super::utils::{emit_packed_kinsn_call_with_off, ensure_btf_fd_slot, fixup_all_branches};
/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/cond_select.rs:284:                let replacement = emit_packed_kinsn_call_with_off(payload, btf_id, kfunc_off);

exec
/bin/bash -lc 'rg -n "struct bpf_kinsn|instantiate_insn|emit_x86|emit_arm64|There is no active `model_call'"\\(\\)"'` or `bpf_kinsn_effect` path|DEFINE_KINSN_V2_MODULE|bpf_rotate64'"\\(|instantiate_rotate|emit_rotate_x86|bpf_select64\\(|instantiate_select|emit_select_x86|instantiate_extract|emit_extract_x86|instantiate_endian_be16|emit_endian_x86|instantiate_memcpy|emit_memcpy_x86\" /home/yunwei37/workspace/bpf-benchmark/{docs,docs/kinsn-design.md,module}" in /home/yunwei37/workspace/bpf-benchmark
 succeeded in 0ms:
/bin/bash: line 1: model_call(): command not found
/bin/bash: line 1: bpf_kinsn_effect: command not found
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-design.md:57:`instantiate_insn(payload, insn_buf)`, whose verifier path temporarily lowers it
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-design.md:82:### 2.2 Canonical semantics still come from `struct bpf_kinsn`
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-design.md:89:struct bpf_kinsn {
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-design.md:94:	int (*instantiate_insn)(u64 payload, struct bpf_insn *insn_buf);
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-design.md:96:	int (*emit_x86)(u8 *image, u32 *off, bool emit,
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-design.md:98:	int (*emit_arm64)(u32 *image, int *idx, bool emit,
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-design.md:105:- `instantiate_insn()` is the canonical BPF-visible semantics source
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-design.md:144:1. export a stub kfunc such as `__bpf_kfunc void bpf_rotate64(void) {}`
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-design.md:147:   `const struct bpf_kinsn *` descriptors
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-design.md:164:	const struct bpf_kinsn * const *kinsn_descs;
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-design.md:178:- verifier uses `btf_kfunc_kinsn_desc()` to recover the `struct bpf_kinsn *`
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-design.md:198:- resolves the backing `struct bpf_kinsn *` through `fetch_kfunc_meta()` and
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-design.md:226:- it calls `instantiate_insn(payload, proof_buf)`
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-design.md:311:- provide a `const struct bpf_kinsn ..._desc`
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-design.md:312:- implement `instantiate_insn()`
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-design.md:314:- register through `DEFINE_KINSN_V2_MODULE(...)`
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-design.md:375:- `instantiate_insn()` as the canonical semantics source
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-formal-semantics.md:19:- `instantiate_insn()` defines the verifier-visible proof object
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-formal-semantics.md:60:Inst_K(p) = instantiate_insn_K(p)
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-formal-semantics.md:107:emitted by `emit_x86` or `emit_arm64`, when the callback exists and succeeds.
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-formal-semantics.md:127:- **Emit purity**: `emit_x86(p, prog)` and `emit_arm64(p, prog)` are
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-formal-semantics.md:209:`instantiate_insn(p)` and native emit callbacks may fail (return negative).
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-formal-semantics.md:214:| `instantiate_insn` returns error | `lower_kinsn_proof_regions()` | Verifier rejects the program |
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-formal-semantics.md:573:  alias `cond` — enforced by emit ordering in `emit_select_x86`
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-design.md:57:`instantiate_insn(payload, insn_buf)`, whose verifier path temporarily lowers it
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-design.md:82:### 2.2 Canonical semantics still come from `struct bpf_kinsn`
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-design.md:89:struct bpf_kinsn {
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-design.md:94:	int (*instantiate_insn)(u64 payload, struct bpf_insn *insn_buf);
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-design.md:96:	int (*emit_x86)(u8 *image, u32 *off, bool emit,
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-design.md:98:	int (*emit_arm64)(u32 *image, int *idx, bool emit,
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-design.md:105:- `instantiate_insn()` is the canonical BPF-visible semantics source
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-design.md:144:1. export a stub kfunc such as `__bpf_kfunc void bpf_rotate64(void) {}`
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-design.md:147:   `const struct bpf_kinsn *` descriptors
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-design.md:164:	const struct bpf_kinsn * const *kinsn_descs;
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-design.md:178:- verifier uses `btf_kfunc_kinsn_desc()` to recover the `struct bpf_kinsn *`
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-design.md:198:- resolves the backing `struct bpf_kinsn *` through `fetch_kfunc_meta()` and
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-design.md:226:- it calls `instantiate_insn(payload, proof_buf)`
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-design.md:311:- provide a `const struct bpf_kinsn ..._desc`
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-design.md:312:- implement `instantiate_insn()`
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-design.md:314:- register through `DEFINE_KINSN_V2_MODULE(...)`
/home/yunwei37/workspace/bpf-benchmark/docs/kinsn-design.md:375:- `instantiate_insn()` as the canonical semantics source
/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md:202:| **ROTATE** | 是 | ✅ 已实现 | shift+or → `bpf_rotate64()` kinsn → JIT emit RORX | 701 sites, 15 applied |
/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md:203:| **COND_SELECT** | 是 | ✅ 已实现 | branch+mov → `bpf_select64()` kinsn → JIT emit CMOV。policy-sensitive | 12 corpus applied |
/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md:311:**`bpf_kinsn_ops`** 包含三类回调：`model_call`（返回声明式 `bpf_kinsn_effect`，含 clobber_mask/result range/tnum/mem_accesses）、`decode_call`/`validate_call`（编码解析和校验）、`emit_x86`/`emit_arm64`（JIT 发射）。
/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md:624:| **323** | **ARM64 inline kfunc + kinsn 模块（2026-03-21）** | ✅ | 内核 `bpf.h` +emit_arm64（+12）、`arm64/bpf_jit_comp.c` +dispatch（+44）。`module/arm64/` 3 模块（ROR 4B、CSEL 8B、LSR+AND 20B）。交叉编译通过。+613 行。 |
/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md:723:| **419** | **⚠️ bpf_kinsn_ops 完整设计（2026-03-23）** | ✅ | codex 调研。独立 sidecar `struct bpf_kinsn_ops`（不扩展 btf_kfunc_id_set）。`model_call()` 返回声明式 `bpf_kinsn_effect`（input_mask + clobber_mask + result range/tnum + mem_accesses），不暴露 bpf_reg_state。packed ABI 用 sidecar pseudo-insn（不复用 off 字段）。endian_load 改 const void*。KF_KINSN 替代 KF_INLINE_EMIT。设计报告：`docs/tmp/20260323/kinsn_ops_design_20260323.md`。 |
/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md:767:| **463** | **kinsn v2 instantiate 设计（2026-03-23）** | ✅ 设计完成 | `instantiate_insn()` 方案：kinsn 展开为等价 BPF 指令序列 → verifier 直接 walk → 极简。建议论文前做 compat-v2（保留 sidecar/fd_slot，只切 verifier 从 effect DSL 到 instruction instantiation）。报告：`docs/tmp/20260323/kinsn_v2_instantiate_design_20260323.md`。 |
/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md:810:| **475** | **⚠️ kinsn 统一到 kfunc 路径（消除平行子系统）（2026-03-25）** | 📝 设计完成 | **目标**：消除 kinsn 在 kfunc 旁边建的平行基础设施（独立 UAPI pseudo、独立注册表、独立 desc/BTF 查找、独立 JIT dispatch），统一到标准 kfunc 路径。**核心方案**：module 导出真实 kfunc（`struct bpf_kinsn *bpf_rotate64(void) { return &rotate; }`），用标准 `register_btf_kfunc_id_set()` + `KF_KINSN` flag 注册；daemon emit 的 CALL 改为 `BPF_PSEUDO_KFUNC_CALL` 编码（imm=func btf_id）；verifier 早期 normalize shim 把旧 `PSEUDO_KINSN_CALL` 归一化为 `PSEUDO_KFUNC_CALL`；`check_kfunc_call()` 看到 `KF_KINSN` → proof lowering 旁路（instantiate_insn → verifier walk）；`fixup_kfunc_call()` 对 `KF_KINSN` 跳过 imm rewrite；JIT 在 kfunc CALL 路径内按 `KF_KINSN` 分派到 `emit_x86/emit_arm64`。**保留不变**：sidecar packed ABI、verifier proof lowering/restore 语义、native emit 回调。**可删除**：`kinsn_tab`（prog_aux + btf）、`register_bpf_kinsn_set()`/`unregister`/`btf_try_get_kinsn_desc()`、`add_kinsn_call()`、`fetch_kinsn_desc_meta()`、`bpf_jit_find_kinsn_desc()`/`bpf_jit_get_kinsn_payload()` 独立入口、`BPF_PSEUDO_KINSN_CALL` UAPI（降为 compat shim）、独立 JIT dispatch 分支、BTF_KIND_VAR descriptor 构建链。**预估**：内核 diff 净减 ~150-260 行，消除"平行子系统"审查阻力。调研报告：`docs/tmp/20260325/kinsn_kfunc_unification_research_20260325.md`（opus）+ `docs/tmp/20260325/kinsn_kfunc_unification_codex_research_20260325.md`（codex）。 |
/home/yunwei37/workspace/bpf-benchmark/docs/kernel-jit-optimization-plan.md:811:| **475a** | Module 补真实 kfunc stub + daemon 切 FUNC discovery | 待做 | 10 个 module 文件（x86×5 + arm64×5）各补一个 `noinline struct bpf_kinsn *bpf_xxx(void) { return &desc; }` + `BTF_ID_FLAGS(func, ..., KF_KINSN)` + `register_btf_kfunc_id_set()`。daemon `kfunc_discovery.rs` 从 `find_var_btf_id()` 切到 `find_func_btf_id()`。 |
/home/yunwei37/workspace/bpf-benchmark/docs/bpfrejit-story.md:177:| **ROTATE** | 是 | ✅ | shift+or → `bpf_rotate64()` kinsn → JIT emit RORX |
/home/yunwei37/workspace/bpf-benchmark/docs/bpfrejit-story.md:178:| **COND_SELECT** | 是 | ✅ | branch+mov → `bpf_select64()` kinsn → JIT emit CMOV。policy-sensitive |
/home/yunwei37/workspace/bpf-benchmark/module/include/kinsn_common.h:124:#define DEFINE_KINSN_V2_MODULE(prefix, desc, kfunc_ids, kinsn_desc_array)	\
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_barrier.c:47:const struct bpf_kinsn bpf_speculation_barrier_desc = {
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_barrier.c:51:	.instantiate_insn = instantiate_barrier,
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_barrier.c:52:	.emit_x86 = emit_barrier_x86,
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_barrier.c:55:static const struct bpf_kinsn * const bpf_barrier_kinsn_descs[] = {
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_barrier.c:59:DEFINE_KINSN_V2_MODULE(bpf_barrier,
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_endian.c:156:static int emit_endian_x86(u8 *image, u32 *off, bool emit,
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_endian.c:219:	return emit_endian_x86(image, off, emit, payload, prog, BPF_H);
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_endian.c:225:	return emit_endian_x86(image, off, emit, payload, prog, BPF_W);
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_endian.c:231:	return emit_endian_x86(image, off, emit, payload, prog, BPF_DW);
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_endian.c:234:const struct bpf_kinsn bpf_endian_load16_desc = {
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_endian.c:238:	.instantiate_insn = instantiate_endian16,
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_endian.c:239:	.emit_x86 = emit_endian16_x86,
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_endian.c:242:const struct bpf_kinsn bpf_endian_load32_desc = {
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_endian.c:246:	.instantiate_insn = instantiate_endian32,
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_endian.c:247:	.emit_x86 = emit_endian32_x86,
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_endian.c:250:const struct bpf_kinsn bpf_endian_load64_desc = {
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_endian.c:254:	.instantiate_insn = instantiate_endian64,
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_endian.c:255:	.emit_x86 = emit_endian64_x86,
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_endian.c:258:static const struct bpf_kinsn * const bpf_endian_kinsn_descs[] = {
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_endian.c:264:DEFINE_KINSN_V2_MODULE(bpf_endian, "BpfReJIT kinsn: ENDIAN_LOAD",
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_bulk_memory.c:131:static int instantiate_memcpy(u64 payload, struct bpf_insn *insn_buf)
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_bulk_memory.c:343:static int emit_memcpy_x86(u8 *image, u32 *off, bool emit,
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_bulk_memory.c:449:const struct bpf_kinsn bpf_memcpy_bulk_desc = {
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_bulk_memory.c:453:	.instantiate_insn = instantiate_memcpy,
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_bulk_memory.c:454:	.emit_x86 = emit_memcpy_x86,
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_bulk_memory.c:457:const struct bpf_kinsn bpf_memset_bulk_desc = {
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_bulk_memory.c:461:	.instantiate_insn = instantiate_memset,
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_bulk_memory.c:462:	.emit_x86 = emit_memset_x86,
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_bulk_memory.c:465:static const struct bpf_kinsn * const bpf_bulk_memory_kinsn_descs[] = {
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_bulk_memory.c:470:DEFINE_KINSN_V2_MODULE(bpf_bulk_memory,
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_extract.c:33:static int instantiate_extract(u64 payload, struct bpf_insn *insn_buf)
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_extract.c:96:static int emit_extract_x86(u8 *image, u32 *off, bool emit,
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_extract.c:129:const struct bpf_kinsn bpf_extract64_desc = {
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_extract.c:133:	.instantiate_insn = instantiate_extract,
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_extract.c:134:	.emit_x86 = emit_extract_x86,
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_extract.c:137:static const struct bpf_kinsn * const bpf_extract_kinsn_descs[] = {
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_extract.c:141:DEFINE_KINSN_V2_MODULE(bpf_extract, "BpfReJIT kinsn: BITFIELD_EXTRACT",
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_rotate.c:9:__bpf_kfunc void bpf_rotate64(void) {}
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_rotate.c:35:static int instantiate_rotate(u64 payload, struct bpf_insn *insn_buf)
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_rotate.c:95:static int emit_rotate_x86(u8 *image, u32 *off, bool emit,
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_rotate.c:127:const struct bpf_kinsn bpf_rotate64_desc = {
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_rotate.c:131:	.instantiate_insn = instantiate_rotate,
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_rotate.c:132:	.emit_x86 = emit_rotate_x86,
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_rotate.c:135:static const struct bpf_kinsn * const bpf_rotate_kinsn_descs[] = {
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_rotate.c:139:DEFINE_KINSN_V2_MODULE(bpf_rotate, "BpfReJIT kinsn: ROTATE (ROL)",
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_select.c:9:__bpf_kfunc void bpf_select64(void) {}
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_select.c:38:static int instantiate_select(u64 payload, struct bpf_insn *insn_buf)
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_select.c:102:static int emit_select_x86(u8 *image, u32 *off, bool emit,
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_select.c:148:const struct bpf_kinsn bpf_select64_desc = {
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_select.c:152:	.instantiate_insn = instantiate_select,
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_select.c:153:	.emit_x86 = emit_select_x86,
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_select.c:156:static const struct bpf_kinsn * const bpf_select_kinsn_descs[] = {
/home/yunwei37/workspace/bpf-benchmark/module/x86/bpf_select.c:160:DEFINE_KINSN_V2_MODULE(bpf_select, "BpfReJIT kinsn: COND_SELECT (CMOV)",
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_extract.c:33:static int instantiate_extract(u64 payload, struct bpf_insn *insn_buf)
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_extract.c:93:const struct bpf_kinsn bpf_extract64_desc = {
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_extract.c:97:	.instantiate_insn = instantiate_extract,
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_extract.c:98:	.emit_arm64 = emit_extract_arm64,
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_extract.c:101:static const struct bpf_kinsn * const bpf_extract_kinsn_descs[] = {
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_extract.c:105:DEFINE_KINSN_V2_MODULE(bpf_extract, "BpfReJIT kinsn: BITFIELD_EXTRACT",
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_rotate.c:9:__bpf_kfunc void bpf_rotate64(void) {}
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_rotate.c:35:static int instantiate_rotate(u64 payload, struct bpf_insn *insn_buf)
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_rotate.c:98:const struct bpf_kinsn bpf_rotate64_desc = {
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_rotate.c:102:	.instantiate_insn = instantiate_rotate,
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_rotate.c:103:	.emit_arm64 = emit_rotate_arm64,
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_rotate.c:106:static const struct bpf_kinsn * const bpf_rotate_kinsn_descs[] = {
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_rotate.c:110:DEFINE_KINSN_V2_MODULE(bpf_rotate, "BpfReJIT kinsn: ROTATE (EXTR)",
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_select.c:9:__bpf_kfunc void bpf_select64(void) {}
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_select.c:38:static int instantiate_select(u64 payload, struct bpf_insn *insn_buf)
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_select.c:108:const struct bpf_kinsn bpf_select64_desc = {
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_select.c:112:	.instantiate_insn = instantiate_select,
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_select.c:113:	.emit_arm64 = emit_select_arm64,
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_select.c:116:static const struct bpf_kinsn * const bpf_select_kinsn_descs[] = {
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_select.c:120:DEFINE_KINSN_V2_MODULE(bpf_select, "BpfReJIT kinsn: COND_SELECT (CSEL)",
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_ldp.c:191:const struct bpf_kinsn bpf_ldp128_desc = {
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_ldp.c:195:	.instantiate_insn = instantiate_ldp,
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_ldp.c:196:	.emit_arm64 = emit_ldp_arm64,
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_ldp.c:199:const struct bpf_kinsn bpf_stp128_desc = {
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_ldp.c:203:	.instantiate_insn = instantiate_stp,
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_ldp.c:204:	.emit_arm64 = emit_stp_arm64,
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_ldp.c:207:static const struct bpf_kinsn * const bpf_ldp_kinsn_descs[] = {
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_ldp.c:212:DEFINE_KINSN_V2_MODULE(bpf_ldp, "BpfReJIT kinsn: pair load/store (LDP/STP)",
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_endian.c:289:const struct bpf_kinsn bpf_endian_load16_desc = {
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_endian.c:293:	.instantiate_insn = instantiate_endian16,
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_endian.c:294:	.emit_arm64 = emit_endian_load16_arm64,
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_endian.c:297:const struct bpf_kinsn bpf_endian_load32_desc = {
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_endian.c:301:	.instantiate_insn = instantiate_endian32,
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_endian.c:302:	.emit_arm64 = emit_endian_load32_arm64,
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_endian.c:305:const struct bpf_kinsn bpf_endian_load64_desc = {
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_endian.c:309:	.instantiate_insn = instantiate_endian64,
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_endian.c:310:	.emit_arm64 = emit_endian_load64_arm64,
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_endian.c:313:static const struct bpf_kinsn * const bpf_endian_kinsn_descs[] = {
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_endian.c:319:DEFINE_KINSN_V2_MODULE(bpf_endian, "BpfReJIT kinsn: ENDIAN_LOAD (REV)",
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_barrier.c:60:const struct bpf_kinsn bpf_speculation_barrier_desc = {
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_barrier.c:64:	.instantiate_insn = instantiate_barrier,
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_barrier.c:65:	.emit_arm64 = emit_barrier_arm64,
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_barrier.c:68:static const struct bpf_kinsn * const bpf_barrier_kinsn_descs[] = {
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_barrier.c:72:DEFINE_KINSN_V2_MODULE(bpf_barrier,
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_bulk_memory.c:135:static int instantiate_memcpy_bulk(u64 payload, struct bpf_insn *insn_buf)
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_bulk_memory.c:558:const struct bpf_kinsn bpf_memcpy_bulk_desc = {
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_bulk_memory.c:562:	.instantiate_insn = instantiate_memcpy_bulk,
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_bulk_memory.c:563:	.emit_arm64 = emit_memcpy_bulk_arm64,
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_bulk_memory.c:566:const struct bpf_kinsn bpf_memset_bulk_desc = {
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_bulk_memory.c:570:	.instantiate_insn = instantiate_memset_bulk,
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_bulk_memory.c:571:	.emit_arm64 = emit_memset_bulk_arm64,
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_bulk_memory.c:574:static const struct bpf_kinsn * const bpf_bulk_memory_kinsn_descs[] = {
/home/yunwei37/workspace/bpf-benchmark/module/arm64/bpf_bulk_memory.c:579:DEFINE_KINSN_V2_MODULE(bpf_bulk_memory,

diff --git a/docs/tmp/20260328/kinsn_vs_kfunc_novelty_20260328.md b/docs/tmp/20260328/kinsn_vs_kfunc_novelty_20260328.md
new file mode 100644
index 0000000000000000000000000000000000000000..f65466f4f3326c56196ecf1fa0829f5f1c240e23
--- /dev/null
++ b/docs/tmp/20260328/kinsn_vs_kfunc_novelty_20260328.md
@@ -0,0 +1,493 @@
# kinsn vs kfunc：本质差异与 novelty 论证

日期：2026-03-28  
目标：回应 reviewer 的质疑

> “如果 kinsn 本质上就是 kfunc + KF_INLINE_EMIT + emit callback，那第 3 节把它包装成独立 bytecode abstraction / extended ISA 就显得过度陈述。kinsn 相对已有 kfunc，到底多了什么不可替代的新能力？”

## 0. 先给结论

基于当前代码树，`kinsn` 不能被准确描述成“普通 kfunc 加一个 inline emit 回调”。  
它和普通 `kfunc` 的本质差异在于：

1. **语义源不同**：普通 `kfunc` 的 verifier 语义来自“BTF 原型 + flags”，函数体是黑盒；`kinsn` 的 verifier 语义来自 `instantiate_insn()` 生成的 ordinary-BPF proof sequence，verifier 真正逐条验证这段 proof sequence，而不是把它当黑盒 call。  
   代码证据：`vendor/linux-framework/include/linux/bpf.h:968-979`，`vendor/linux-framework/kernel/bpf/verifier.c:3669-3835`，`vendor/linux-framework/kernel/bpf/verifier.c:26408-26484`。

2. **抽象层级不同**：普通 `kfunc` 仍然是“函数调用”；`kinsn` 是“指令形式”的 transport。daemon 发出的不是 `BPF_PSEUDO_KFUNC_CALL`，而是“`sidecar + BPF_PSEUDO_KINSN_CALL`”这一对专用 bytecode 形式，payload 直接携带结果寄存器、输入寄存器、offset 等操作数字段。  
   代码证据：`daemon/src/insn.rs:243-290`，`vendor/linux-framework/include/linux/bpf.h:996-1007`，`vendor/linux-framework/kernel/bpf/verifier.c:21355-21476`。

3. **执行路径不同**：普通 `kfunc` 在 JIT 里被解析为真正的 runtime function call；`kinsn` 在 JIT 里根本不走函数地址调用，而是直接根据 descriptor + payload 发 native code。  
   代码证据：普通 `kfunc` 路径 `vendor/linux-framework/kernel/bpf/verifier.c:3542-3566` 与 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2477-2499`；`kinsn` 路径 `vendor/linux-framework/kernel/bpf/verifier.c:3524-3541`、`vendor/linux-framework/kernel/bpf/verifier.c:3882-3910`、`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:579-606`、`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2477-2483`。

4. **降级路径不同**：普通 `kfunc` 缺失时，调用点不可成立；BpfReJIT 的 `kinsn` pass 在 module/BTF 不可发现时直接不改写原程序，程序照常跑原始 eBPF；即便改写后缺少 native emit，kernel 也能回退到 proof sequence。  
   代码证据：`daemon/src/kfunc_discovery.rs:352-381`，`daemon/src/passes/rotate.rs:29-56`，`daemon/src/passes/cond_select.rs:143-171`，`vendor/linux-framework/kernel/bpf/verifier.c:23755-23795`。

因此，**复用 kfunc 注册/发现基础设施，只是 plumbing reuse；并不把 kinsn 降格成“普通 kfunc 的语义子集”**。  
真正独立存在的是三件东西：`sidecar` transport、proof-lowering verifier path、native emit dispatch。

---

## 1. 一个必须先纠正的前提：当前树里没有 `bpf_kinsn_effect / model_call`

题目背景里提到的 `bpf_kinsn_ops` / `bpf_kinsn_effect` / `model_call()`，**不是当前 in-tree 实现**。

当前 `include/linux/bpf.h` 里真正存在的是：

```c
struct bpf_kinsn {
	struct module *owner;
	u16 max_insn_cnt;
	u16 max_emit_bytes;
	int (*instantiate_insn)(u64 payload, struct bpf_insn *insn_buf);
	int (*emit_x86)(u8 *image, u32 *off, bool emit, u64 payload, const struct bpf_prog *prog);
	int (*emit_arm64)(u32 *image, int *idx, bool emit, u64 payload, const struct bpf_prog *prog);
};
```

代码证据：`vendor/linux-framework/include/linux/bpf.h:968-979`。  
设计文档也明确写了：**“There is no active `model_call()` or `bpf_kinsn_effect` path in the current tree.”**  
证据：`docs/kinsn-design.md:103-109`。

这意味着：

- 当前 tree 中，`kinsn` 的 verifier 语义不是 declarative effect DSL。
- 当前 tree 中，`kinsn` 的 verifier 语义来源是 `instantiate_insn()` 生成的 ordinary-BPF proof sequence。
- 因此，下面的 novelty 论证必须以 **proof-lowering model** 为准，而不能再按旧版 effect DSL 叙述。

这点很重要，因为 reviewer 如果按当前代码审读，你在正文里继续强调 `bpf_kinsn_effect`，会立刻被抓住“实现与论证不一致”。

---

## 2. 一张总表：普通 kfunc 与当前 kinsn 的真正差异

| 维度 | 普通 kfunc | 当前 kinsn |
| --- | --- | --- |
| 注册入口 | `register_btf_kfunc_id_set()` | 也复用 `register_btf_kfunc_id_set()`，但额外挂接 `kinsn_descs` |
| bytecode 编码 | `BPF_PSEUDO_KFUNC_CALL` | `sidecar + BPF_PSEUDO_KINSN_CALL` |
| verifier 看到什么 | call 指令；按 BTF prototype / flags 做参数与返回值建模 | 先被 lower 成 ordinary-BPF proof sequence，再跑标准 verifier |
| 语义源 | BTF 原型 + flags；函数体黑盒 | `instantiate_insn()` 生成的 proof sequence |
| JIT 执行 | 真实 `call` 到 kernel function 地址 | 直接 `emit_x86/emit_arm64` 内联发码 |
| 是否需要函数地址 | 需要：`kallsyms_lookup_name()` | 不需要：只需要 descriptor + payload |
| 操作数传递 | 走 R1-R5 调用 ABI，返回值在 R0 | payload 里直接携带 dst/src/off 等字段 |
| module 缺失时 | 调用点不可成立 | daemon 直接不改写原程序；已改写但无 native emit 时还能回退 proof sequence |
| 是否仍是“函数调用”抽象 | 是 | 否，已经是专用 instruction form |

对应代码：

- 复用注册入口但额外挂接 `kinsn_descs`：`vendor/linux-framework/include/linux/btf.h:122-127`，`vendor/linux-framework/kernel/bpf/btf.c:8784-8816`。
- 普通 `kfunc` 查到的是 `addr + func_model`：`vendor/linux-framework/kernel/bpf/verifier.c:3542-3566`。
- `kinsn` 查到的是 `desc->kinsn` 而不是函数地址：`vendor/linux-framework/kernel/bpf/verifier.c:3524-3541`。
- 普通 call bytecode 与 kinsn bytecode 区分：`daemon/src/insn.rs:223-255`。
- sidecar payload 编码：`daemon/src/insn.rs:277-290`，`vendor/linux-framework/include/linux/bpf.h:996-1007`。

---

## 3. “用 kfunc infra 实现”只是 plumbing reuse，不是语义等价

### 3.1 共享的是注册表，不是 verifier/JIT 语义

`kinsn` 的确复用了 kfunc 注册基础设施：

- `struct btf_kfunc_id_set` 多了 `const struct bpf_kinsn * const *kinsn_descs;`  
  证据：`vendor/linux-framework/include/linux/btf.h:122-127`
- 注册时，`btf_populate_kfunc_set()` 把 `(btf_id -> kinsn desc)` 填入独立的 `kinsn_sets`  
  证据：`vendor/linux-framework/kernel/bpf/btf.c:8784-8816`
- 查询时，`btf_kfunc_kinsn_desc()` 从这个附加表里取 descriptor  
  证据：`vendor/linux-framework/kernel/bpf/btf.c:8987-9005`

但是从 verifier 开始，普通 `kfunc` 与 `kinsn` 立即分叉：

- 普通 `kfunc` 分支：查 symbol 地址、蒸馏 `btf_func_model`、最终发出 runtime call  
  证据：`vendor/linux-framework/kernel/bpf/verifier.c:3542-3566`
- `kinsn` 分支：要求 `instantiate_insn != NULL`，保存 `desc->kinsn`，完全不取函数地址  
  证据：`vendor/linux-framework/kernel/bpf/verifier.c:3524-3541`

因此，**“用 kfunc infra 实现”只能推出 registration path 被复用，不能推出 semantic abstraction 没有新东西**。

### 3.2 如果将来统一到 kfunc 路径，也不等于 kinsn 不需要独立存在

即使把 `PSEUDO_KINSN_CALL` 统一编码到 `PSEUDO_KFUNC_CALL`，只要下面三样还在，`kinsn` 仍是独立抽象：

1. sidecar payload transport
2. proof-lowering verifier path
3. native emit dispatch

换句话说，**可以统一 plumbing，但不能消掉 abstraction**。  
消掉这三样之后，剩下的才只是“普通 kfunc 调用”。

---

## 4. verifier 本质差异：普通 kfunc 是黑盒 call，kinsn 是 proof-visible instruction

## 4.1 普通 kfunc：verifier 不看函数体，只看原型/flags

普通 `kfunc` 的元数据来自：

- BTF function prototype
- kfunc flags
- 允许性检查

证据：

- `fetch_kfunc_meta()` 从 BTF 取 `func_proto`、`func_name`、`kfunc_flags`：`vendor/linux-framework/kernel/bpf/verifier.c:3405-3449`
- `fetch_kfunc_arg_meta()` 只把 `btf/proto/name/flags` 填入 `meta`：`vendor/linux-framework/kernel/bpf/verifier.c:14203-14226`
- `check_kfunc_args()` 逐个参数按 BTF 类型做检查：`vendor/linux-framework/kernel/bpf/verifier.c:13656-14120`
- 返回值按 BTF 返回类型建模：`vendor/linux-framework/kernel/bpf/verifier.c:14650-14779`
- 调用后统一 clobber caller-saved regs：`vendor/linux-framework/kernel/bpf/verifier.c:14643-14648`

普通 `kfunc` descriptor 里保存的是：

```c
struct bpf_kfunc_desc {
	struct btf_func_model func_model;
	const struct bpf_kinsn *kinsn;
	u32 func_id;
	s32 imm;
	u16 offset;
	unsigned long addr;
};
```

证据：`vendor/linux-framework/kernel/bpf/verifier.c:3180-3187`。

对普通 `kfunc`，最终被填充的是 `addr` 和 `func_model`，而不是 `kinsn`：

- `addr = kallsyms_lookup_name(kfunc.name)`  
- `btf_distill_func_proto(..., &func_model)`  
- `desc->addr = addr; desc->func_model = func_model;`

证据：`vendor/linux-framework/kernel/bpf/verifier.c:3542-3566`，`vendor/linux-framework/kernel/bpf/btf.c:7485-7553`。

这说明普通 `kfunc` 的 verifier 视角始终是：“这是一个黑盒函数调用；我只知道签名，不知道函数体。”

## 4.2 kinsn：verifier 真正验证的是 instantiated proof sequence

`kinsn` 走的是完全不同的路径：

1. `add_subprog_and_kfunc()` 识别 `BPF_PSEUDO_KINSN_CALL`，统计 `env->kinsn_call_cnt`，并以 `kinsn_call=true` 注册 descriptor。  
   证据：`vendor/linux-framework/kernel/bpf/verifier.c:3928-3963`

2. `lower_kinsn_proof_regions()` 在主 verifier 之前，把每个 `sidecar + kinsn_call` 替换成 `instantiate_insn(payload)` 生成的 proof sequence。  
   证据：`vendor/linux-framework/kernel/bpf/verifier.c:3723-3835`

3. verifier 随后对 lowered 程序跑标准流程：`check_subprogs()`、`check_cfg()`、`compute_postorder()`、`compute_scc()`、`compute_live_registers()`、`do_check_main()`、`do_check_subprogs()`。  
   证据：`vendor/linux-framework/kernel/bpf/verifier.c:26408-26484`

4. 验证成功后，再 `restore_kinsn_proof_regions()` 把 proof sequence 恢复回原始 sidecar+call transport。  
   证据：`vendor/linux-framework/kernel/bpf/verifier.c:3837-3879`，`vendor/linux-framework/kernel/bpf/verifier.c:26479-26484`

还要注意两条非常强的证据：

- verifier 明确禁止“未 lowering 的 kinsn call”继续走普通 call 检查：  
  `internal error: kinsn call reached verifier without proof lowering`  
  证据：`vendor/linux-framework/kernel/bpf/verifier.c:21474-21476`

- `check_kinsn_sidecar_insn()` 只做 transport 完整性检查，要求 sidecar 后面必须立刻跟 kinsn call。  
  证据：`vendor/linux-framework/kernel/bpf/verifier.c:21355-21372`

所以，**当前 tree 中 kinsn 的 verifier 语义来源不是 call rule，而是 proof-lowering 后的 ordinary BPF**。  
这已经足以把它和普通 `kfunc` 区分开。

## 4.3 这比“普通 kfunc + emit callback”多了什么？

多出来的是：**call 站点不再被 verifier 当作 opaque function invocation，而被当作一个可以展开、验证、恢复的 instruction-form object。**

这正是 reviewer 质疑中的关键误区。  
如果只是“普通 kfunc + emit callback”，verifier 侧仍然会停留在 `check_kfunc_call()` 这条黑盒语义路径上。  
当前 `kinsn` 不是这样；它有一整条独立的 proof-lowering verifier path。

## 4.4 需要诚实加上的一个 caveat

如果按你最初的 `bpf_kinsn_effect` 说法，结论会更强：module 只能声明 effect，core verifier 强制执行 effect。  
**但这不是当前 tree 的实现。**

当前 tree 的真实安全叙述应更精确地写成：

- **BPF-visible safety** 来自 ordinary-BPF proof sequence 的标准 verifier；
- **native correctness** 额外依赖 `emit_x86/emit_arm64` 对 `instantiate_insn()` 的 refinement。

也就是说，当前 tree 确实比普通 `kfunc` 更“可验证”，但它的 novelty 是 **proof-visible instruction semantics**，不是更强的 **effect-DSL trust narrowing**。

---

## 5. 抽象层级差异：函数调用 vs 指令形式

## 5.1 普通 kfunc 仍然是 call ABI

普通 BPF call 的 helper/kfunc 原型是固定走寄存器 ABI 的：`func(u64 r1, u64 r2, u64 r3, u64 r4, u64 r5)`。  
证据：`vendor/linux-framework/include/linux/bpf.h:924-965`。

如果把一个局部 peephole 重写成普通 `kfunc`，即便语义上可行，也仍然要承担：

- 参数搬运到 R1-R5
- runtime `call` / `ret`
- 返回值从 R0 再搬回目标寄存器
- caller-saved clobber 语义

这仍然是**函数级**抽象。

## 5.2 kinsn transport 是专用 instruction form

daemon 发出的 kinsn 不是普通 call，而是：

1. `BpfInsn::kinsn_sidecar(payload)`
2. `BpfInsn::call_kinsn_with_off(btf_id, off)`

证据：`daemon/src/passes/utils.rs:281-292`，`daemon/src/insn.rs:243-290`。

payload 直接编码：

- 结果寄存器
- 输入寄存器
- offset
- 立即数参数

因此，**operand/result placement 是 payload-level，而不是 ABI-level**。

`emit_packed_kinsn_call_with_off()` 的注释甚至明确写了：

> “The result register is part of `payload`, so no extra `mov dst, r0` is emitted here.”

证据：`daemon/src/passes/utils.rs:281-292`。

这就是为什么它是 instruction abstraction，而不是 function abstraction。

## 5.3 具体 pass 里，替换粒度就是 instruction-form 粒度

### rotate

- 识别的是 `MOV provenance + RSH + LSH + OR` 窗口  
  证据：`daemon/src/passes/rotate.rs:239-360`
- `old_len = (pc + 3) - mov_pc`，即典型 4→2 BPF transport 替换  
  证据：`daemon/src/passes/rotate.rs:294-309`
- native emit 不是函数调用，而是 x86 `mov + rol` 或 ARM64 `EXTR`  
  证据：`module/x86/bpf_rotate.c:95-125`，`module/arm64/bpf_rotate.c:68-95`

### cond_select

- 识别 4-insn diamond 或 3-insn short pattern  
  证据：`daemon/src/passes/cond_select.rs:327-411`
- `old_len` 分别为 4 或 3  
  证据：`daemon/src/passes/cond_select.rs:361`，`daemon/src/passes/cond_select.rs:411`
- native emit 是 x86 `test + cmov` 或 ARM64 `tst + csel`  
  证据：`module/x86/bpf_select.c:102-146`，`module/arm64/bpf_select.c:71-105`

### extract

- 识别 `RSH + AND` 两条指令  
  证据：`daemon/src/passes/extract.rs:55-94`
- `old_len = 2`，替换成 2-insn transport  
  证据：`daemon/src/passes/extract.rs:77-83`，`daemon/src/passes/extract.rs:196-200`
- native emit 是直接内联 bitfield extract sequence，而不是 helper body call  
  证据：`module/x86/bpf_extract.c:96-127`，`module/arm64/bpf_extract.c:64-90`

### endian_fusion

- 识别 `LDX_MEM + ENDIAN_TO_BE`  
  证据：`daemon/src/passes/endian.rs:17-33`，`daemon/src/passes/endian.rs:53-107`
- 直接把 offset 编进 payload；必要时也只是在 packed transport 周围补地址物化，而不是切回 legacy call ABI  
  证据：`daemon/src/passes/endian.rs:155-210`
- 注释明确说“instead of using any legacy call ABI”  
  证据：`daemon/src/passes/endian.rs:30-33`

### bulk_memory

- 识别大段 scalarized memcpy/memset  
  证据：`daemon/src/passes/bulk_memory.rs:92-93`
- `MIN_BULK_BYTES = 32`，`CHUNK_MAX_BYTES = 128`  
  证据：`daemon/src/passes/bulk_memory.rs:12-18`
- 每个 chunk 仅发出 `2` 条 transport 指令  
  证据：`daemon/src/passes/bulk_memory.rs:529-547`，`daemon/src/passes/bulk_memory.rs:557-573`
- verifier proof sequence 却可以展开为最多 `128*2` 条 bytewise memcpy 指令  
  证据：`module/x86/bpf_bulk_memory.c:131-150`，`module/x86/bpf_bulk_memory.c:449-455`

这类“**大窗口 -> 单个逻辑指令 -> 小 native 序列**”的替换，正是普通 `kfunc` 难以等价替代的地方。

---

## 6. 优雅降级：这也是普通 kfunc 不具备的产品级属性

## 6.1 module 没加载时，daemon 直接保持原始 bytecode

discovery 阶段如果 `/sys/kernel/btf/<module>` 不存在，就把该 target 标成 unavailable：

- `module '<name>' not loaded (no BTF at ...)`
- 对应 `registry.*_btf_id` 保持 `-1`

证据：`daemon/src/kfunc_discovery.rs:311-381`。

各 pass 在发现 target 不可用时，直接 `changed=false` 返回，不改原程序：

- rotate：`daemon/src/passes/rotate.rs:29-41`
- cond_select：`daemon/src/passes/cond_select.rs:143-171`
- extract：`daemon/src/passes/extract.rs:111-138`
- endian_fusion：`daemon/src/passes/endian.rs:228-266`
- bulk_memory：`daemon/src/passes/bulk_memory.rs:151-175`

这意味着 **module 缺失不会导致应用程序不能运行，只会让优化 pass 不生效**。

## 6.2 module 存在但当前架构/后端没有 native emit 时，kernel 回退到 proof sequence

在 `do_misc_fixups()` 里：

- 若 `prog->jit_requested && bpf_kinsn_has_native_emit(kinsn)`，保留 sidecar+call 给 JIT 原生发码；
- 否则，就把 sidecar+call 替换成 `instantiate_insn()` 生成的 proof sequence。

证据：`vendor/linux-framework/kernel/bpf/verifier.c:23755-23795`。

所以 kinsn 有两层 graceful degradation：

1. **用户态 pass 层**：没发现 module，就不改写
2. **内核 JIT 层**：发现了 kinsn 但没 native emit，也还能退回 ordinary BPF

这比“硬依赖某个 kfunc 必须存在，否则 load fail”更平滑。

---

## 7. “纯用 kfunc 能不能做出同样效果？”答案是：不能等价复制当前实现的关键性质

## 7.1 代码已经表明这些 pass 依赖的是 packed kinsn，而不是普通 kfunc

当前真正使用 `emit_packed_kinsn_call_with_off()` 的 pass 一共有 5 个：

1. `bulk_memory`
2. `rotate`
3. `cond_select`
4. `extract`
5. `endian_fusion`

证据：

- `daemon/src/passes/bulk_memory.rs`
- `daemon/src/passes/rotate.rs`
- `daemon/src/passes/cond_select.rs`
- `daemon/src/passes/extract.rs`
- `daemon/src/passes/endian.rs`

这些 pass 发出的都是 `BPF_PSEUDO_KINSN_CALL`，不是 `BPF_PSEUDO_KFUNC_CALL`。  
证据：`daemon/src/passes/utils.rs:281-292`，以及各 pass 的 replacement 构造代码。

## 7.2 某些 pass 明确拒绝回退到 legacy call ABI

最清楚的是 `endian_fusion` 和 `cond_select`：

- `endian_fusion` 注释明确说，即便 offset 不能直接编码，也是在 packed transport 周围补地址计算，**“instead of using any legacy call ABI”**。  
  证据：`daemon/src/passes/endian.rs:30-33`

- `cond_select` 如果 true/false 不是寄存器值，就直接 skip，原因是 packed path 需要 register operands；它没有实现任何“普通 kfunc ABI fallback”。  
  证据：`daemon/src/passes/cond_select.rs:104-111`，`daemon/src/passes/cond_select.rs:227-233`

这不是偶然，而是实现者明确在说：**纯 kfunc ABI 不是这个抽象想要的东西。**

## 7.3 普通 kfunc 只能给你“call 一个函数”，而不是“在 bytecode 中保留一个 instruction site”

如果没有 `kinsn`，你最多能做到：

- 把 peephole pattern 改写成普通 `kfunc` 调用；
- 希望 JIT 再特殊识别这个 call 去做 inline emit。

但这样依然缺 3 个核心能力：

1. verifier 不会把它当 proof-visible instruction，只会走黑盒 call rule；
2. bytecode 中没有独立的 sidecar payload instruction form；
3. daemon 无法在不占用 R1-R5 ABI 的情况下，把 dst/src/off 等局部语义原样保留到后端。

换言之，**没有 kinsn，你可以伪装出“可 inline 的函数调用”；但你得不到“可验证、可恢复、可携带 operand payload 的指令形式”。**

---

## 8. 量化：当前仓库里到底有多少优化依赖 kinsn？

`PASS_REGISTRY` 一共注册了 12 个 pass：  
证据：`daemon/src/passes/mod.rs:52-118`

其中 **5 个直接依赖 kinsn packed transport**：

1. `bulk_memory`
2. `rotate`
3. `cond_select`
4. `extract`
5. `endian_fusion`

其余 **7 个是纯 bytecode 变换，不依赖 kinsn**：

1. `map_inline`
2. `const_prop`
3. `dce`
4. `skb_load_bytes_spec`
5. `bounds_check_merge`
6. `wide_mem`
7. `branch_flip`

特别是 `wide_mem` 的注释写得很直白：

> “No kinsn support needed -- pure BPF replacement.”

证据：`daemon/src/passes/wide_mem.rs:380-385`。

因此，从现有实现看：

- **kinsn 不是整个系统的必要条件**；
- 但它确实支撑了一组独立的、不可用纯 bytecode pass 替代的指令级 peephole 优化；
- reviewer 如果问 “到底多了什么新能力”，答案不是“所有优化都靠 kinsn”，而是“**某一类 instruction-form peephole optimization 需要它**”。

## 8.1 静态替换规模

| pass | 典型原始窗口 | BPF transport | native emit |
| --- | --- | --- | --- |
| rotate | 4 insns | 2 insns | x86 `mov+rol` / ARM64 `EXTR` |
| cond_select | 3 或 4 insns | 2 insns | x86 `test+cmov` / ARM64 `tst+csel` |
| extract | 2 insns | 2 insns | x86 inline extract seq / ARM64 `UBFM` |
| endian_fusion | 2 insns | 2 insns（少数场景 3-4） | x86 load+bswap / ARM64 load+REV |
| bulk_memory | 32B~128B 的长 store/load run | 每 chunk 2 insns | x86 `rep movsb/stosb` 或 ARM64 pair-loop |

这张表的重点不是所有 case 都是“N→1 machine insn”，而是：

- `kinsn` 把局部优化机会保留成一个独立的 instruction site；
- JIT 再把它降为短 native 序列；
- 中间没有普通函数调用 ABI 的寄存器搬运与 runtime call。

---

## 9. 给 reviewer 的直接回答

可以把回应压缩成下面这段：

> `kinsn` 复用了 `kfunc` 的注册与发现 plumbing，但它不是普通 `kfunc` 的语义别名。普通 `kfunc` 在 verifier 中是黑盒函数调用，安全模型只基于 BTF prototype 和 flags；当前 `kinsn` 则在主 verifier 之前被 lower 成 ordinary-BPF proof sequence，verifier 真正验证的是这段展开后的 BPF 语义，然后再把 site 恢复成原始 `sidecar + PSEUDO_KINSN_CALL` transport。JIT 阶段，普通 `kfunc` 仍是 runtime call 到 kernel symbol，而 `kinsn` 则根据 payload 直接内联 native code。因此，`kinsn` 的 novelty 不在于“又发明了一条注册 API”，而在于它把目标相关 peephole 优化提升成一种 verifier-visible、bytecode-carried、可原生发码又可回退 proof sequence 的 instruction-form abstraction。没有 kinsn，最多只能得到一个可 inline 的函数调用；得不到当前这种带 sidecar payload、proof-lowering、native emit dispatch 的独立指令抽象。`

---

## 10. 对论文措辞的建议

基于当前代码树，建议正文避免再使用下面这些说法：

- “`bpf_kinsn_effect` 是当前实现”
- “module 只声明 effect，core verifier 强制执行 effect”
- “当前 in-tree novelty 主要来自 declarative effect DSL”

更准确的表述应该是：

1. **当前实现的 novelty**：proof-visible instruction form + packed sidecar transport + native emit refinement + graceful degradation。
2. **不是 novelty 的部分**：kfunc registration plumbing 复用。
3. **如果想讨论 effect DSL**：应明确写成 future design / stronger design point，而不是 current implementation。

否则 reviewer 很容易抓住“文字说的是 effect DSL，代码实现其实是 proof-lowering”这一点。

---

## 11. 最终判断

如果严格基于当前代码树，我的结论是：

- **“kinsn 只是 kfunc + emit callback”这个说法不成立。**
- 但 **“kinsn 的 novelty 来自 declarative effect DSL”这个说法在当前 tree 也不成立。**

当前 tree 能站得住脚的 novelty，是：

1. **专用 bytecode transport**：`sidecar + PSEUDO_KINSN_CALL`
2. **独立 verifier 语义**：proof-lowering，而非黑盒 call
3. **独立 JIT 语义**：descriptor-driven native inline emit，而非 runtime symbol call
4. **双层 graceful degradation**：daemon 不改写 / kernel proof fallback

如果第 3 节按这个版本重写，reviewer 的质疑可以被正面化解；  
如果继续把当前实现写成 `bpf_kinsn_effect` 式的 effect DSL，就会留下明显的可攻击点。

codex
关键锚点没有发现明显偏差。还有一个重要结论需要在交付里点明：当前代码树的 novelty 站得住脚的核心是 `proof-lowering + packed transport + native emit`，不是旧版 `effect DSL` 叙述。
codex
文档已写入 [kinsn_vs_kfunc_novelty_20260328.md](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/kinsn_vs_kfunc_novelty_20260328.md)。我只新增了这一个文档文件，没有修改代码，也没有改 `docs/paper/`。

文档里把 reviewer 的质疑拆成了 verifier 语义、bytecode transport、JIT 执行路径、graceful degradation、pass 依赖范围五部分，并补了代码引用和对比表。一个需要明确指出的结论是：当前代码树并不存在你背景里写的 `bpf_kinsn_effect / model_call()` 现状实现，所以文档把 novelty 重新锚定在“`sidecar + PSEUDO_KINSN_CALL` 的专用 transport、proof-lowering verifier path、descriptor-driven native emit、双层降级”上，而不是旧版 effect DSL 叙述。这一点如果不先校正，reviewer 很容易继续攻击“论文叙述和代码实现不一致”。

如果你要，我下一步可以直接把这份文档再压缩成一版适合放进 rebuttal 或论文第 3 节的英文/中文 paper-ready 表述。
diff --git a/docs/tmp/20260328/kinsn_vs_kfunc_novelty_20260328.md b/docs/tmp/20260328/kinsn_vs_kfunc_novelty_20260328.md
new file mode 100644
index 0000000000000000000000000000000000000000..f65466f4f3326c56196ecf1fa0829f5f1c240e23
--- /dev/null
++ b/docs/tmp/20260328/kinsn_vs_kfunc_novelty_20260328.md
@@ -0,0 +1,493 @@
# kinsn vs kfunc：本质差异与 novelty 论证

日期：2026-03-28  
目标：回应 reviewer 的质疑

> “如果 kinsn 本质上就是 kfunc + KF_INLINE_EMIT + emit callback，那第 3 节把它包装成独立 bytecode abstraction / extended ISA 就显得过度陈述。kinsn 相对已有 kfunc，到底多了什么不可替代的新能力？”

## 0. 先给结论

基于当前代码树，`kinsn` 不能被准确描述成“普通 kfunc 加一个 inline emit 回调”。  
它和普通 `kfunc` 的本质差异在于：

1. **语义源不同**：普通 `kfunc` 的 verifier 语义来自“BTF 原型 + flags”，函数体是黑盒；`kinsn` 的 verifier 语义来自 `instantiate_insn()` 生成的 ordinary-BPF proof sequence，verifier 真正逐条验证这段 proof sequence，而不是把它当黑盒 call。  
   代码证据：`vendor/linux-framework/include/linux/bpf.h:968-979`，`vendor/linux-framework/kernel/bpf/verifier.c:3669-3835`，`vendor/linux-framework/kernel/bpf/verifier.c:26408-26484`。

2. **抽象层级不同**：普通 `kfunc` 仍然是“函数调用”；`kinsn` 是“指令形式”的 transport。daemon 发出的不是 `BPF_PSEUDO_KFUNC_CALL`，而是“`sidecar + BPF_PSEUDO_KINSN_CALL`”这一对专用 bytecode 形式，payload 直接携带结果寄存器、输入寄存器、offset 等操作数字段。  
   代码证据：`daemon/src/insn.rs:243-290`，`vendor/linux-framework/include/linux/bpf.h:996-1007`，`vendor/linux-framework/kernel/bpf/verifier.c:21355-21476`。

3. **执行路径不同**：普通 `kfunc` 在 JIT 里被解析为真正的 runtime function call；`kinsn` 在 JIT 里根本不走函数地址调用，而是直接根据 descriptor + payload 发 native code。  
   代码证据：普通 `kfunc` 路径 `vendor/linux-framework/kernel/bpf/verifier.c:3542-3566` 与 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2477-2499`；`kinsn` 路径 `vendor/linux-framework/kernel/bpf/verifier.c:3524-3541`、`vendor/linux-framework/kernel/bpf/verifier.c:3882-3910`、`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:579-606`、`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2477-2483`。

4. **降级路径不同**：普通 `kfunc` 缺失时，调用点不可成立；BpfReJIT 的 `kinsn` pass 在 module/BTF 不可发现时直接不改写原程序，程序照常跑原始 eBPF；即便改写后缺少 native emit，kernel 也能回退到 proof sequence。  
   代码证据：`daemon/src/kfunc_discovery.rs:352-381`，`daemon/src/passes/rotate.rs:29-56`，`daemon/src/passes/cond_select.rs:143-171`，`vendor/linux-framework/kernel/bpf/verifier.c:23755-23795`。

因此，**复用 kfunc 注册/发现基础设施，只是 plumbing reuse；并不把 kinsn 降格成“普通 kfunc 的语义子集”**。  
真正独立存在的是三件东西：`sidecar` transport、proof-lowering verifier path、native emit dispatch。

---

## 1. 一个必须先纠正的前提：当前树里没有 `bpf_kinsn_effect / model_call`

题目背景里提到的 `bpf_kinsn_ops` / `bpf_kinsn_effect` / `model_call()`，**不是当前 in-tree 实现**。

当前 `include/linux/bpf.h` 里真正存在的是：

```c
struct bpf_kinsn {
	struct module *owner;
	u16 max_insn_cnt;
	u16 max_emit_bytes;
	int (*instantiate_insn)(u64 payload, struct bpf_insn *insn_buf);
	int (*emit_x86)(u8 *image, u32 *off, bool emit, u64 payload, const struct bpf_prog *prog);
	int (*emit_arm64)(u32 *image, int *idx, bool emit, u64 payload, const struct bpf_prog *prog);
};
```

代码证据：`vendor/linux-framework/include/linux/bpf.h:968-979`。  
设计文档也明确写了：**“There is no active `model_call()` or `bpf_kinsn_effect` path in the current tree.”**  
证据：`docs/kinsn-design.md:103-109`。

这意味着：

- 当前 tree 中，`kinsn` 的 verifier 语义不是 declarative effect DSL。
- 当前 tree 中，`kinsn` 的 verifier 语义来源是 `instantiate_insn()` 生成的 ordinary-BPF proof sequence。
- 因此，下面的 novelty 论证必须以 **proof-lowering model** 为准，而不能再按旧版 effect DSL 叙述。

这点很重要，因为 reviewer 如果按当前代码审读，你在正文里继续强调 `bpf_kinsn_effect`，会立刻被抓住“实现与论证不一致”。

---

## 2. 一张总表：普通 kfunc 与当前 kinsn 的真正差异

| 维度 | 普通 kfunc | 当前 kinsn |
| --- | --- | --- |
| 注册入口 | `register_btf_kfunc_id_set()` | 也复用 `register_btf_kfunc_id_set()`，但额外挂接 `kinsn_descs` |
| bytecode 编码 | `BPF_PSEUDO_KFUNC_CALL` | `sidecar + BPF_PSEUDO_KINSN_CALL` |
| verifier 看到什么 | call 指令；按 BTF prototype / flags 做参数与返回值建模 | 先被 lower 成 ordinary-BPF proof sequence，再跑标准 verifier |
| 语义源 | BTF 原型 + flags；函数体黑盒 | `instantiate_insn()` 生成的 proof sequence |
| JIT 执行 | 真实 `call` 到 kernel function 地址 | 直接 `emit_x86/emit_arm64` 内联发码 |
| 是否需要函数地址 | 需要：`kallsyms_lookup_name()` | 不需要：只需要 descriptor + payload |
| 操作数传递 | 走 R1-R5 调用 ABI，返回值在 R0 | payload 里直接携带 dst/src/off 等字段 |
| module 缺失时 | 调用点不可成立 | daemon 直接不改写原程序；已改写但无 native emit 时还能回退 proof sequence |
| 是否仍是“函数调用”抽象 | 是 | 否，已经是专用 instruction form |

对应代码：

- 复用注册入口但额外挂接 `kinsn_descs`：`vendor/linux-framework/include/linux/btf.h:122-127`，`vendor/linux-framework/kernel/bpf/btf.c:8784-8816`。
- 普通 `kfunc` 查到的是 `addr + func_model`：`vendor/linux-framework/kernel/bpf/verifier.c:3542-3566`。
- `kinsn` 查到的是 `desc->kinsn` 而不是函数地址：`vendor/linux-framework/kernel/bpf/verifier.c:3524-3541`。
- 普通 call bytecode 与 kinsn bytecode 区分：`daemon/src/insn.rs:223-255`。
- sidecar payload 编码：`daemon/src/insn.rs:277-290`，`vendor/linux-framework/include/linux/bpf.h:996-1007`。

---

## 3. “用 kfunc infra 实现”只是 plumbing reuse，不是语义等价

### 3.1 共享的是注册表，不是 verifier/JIT 语义

`kinsn` 的确复用了 kfunc 注册基础设施：

- `struct btf_kfunc_id_set` 多了 `const struct bpf_kinsn * const *kinsn_descs;`  
  证据：`vendor/linux-framework/include/linux/btf.h:122-127`
- 注册时，`btf_populate_kfunc_set()` 把 `(btf_id -> kinsn desc)` 填入独立的 `kinsn_sets`  
  证据：`vendor/linux-framework/kernel/bpf/btf.c:8784-8816`
- 查询时，`btf_kfunc_kinsn_desc()` 从这个附加表里取 descriptor  
  证据：`vendor/linux-framework/kernel/bpf/btf.c:8987-9005`

但是从 verifier 开始，普通 `kfunc` 与 `kinsn` 立即分叉：

- 普通 `kfunc` 分支：查 symbol 地址、蒸馏 `btf_func_model`、最终发出 runtime call  
  证据：`vendor/linux-framework/kernel/bpf/verifier.c:3542-3566`
- `kinsn` 分支：要求 `instantiate_insn != NULL`，保存 `desc->kinsn`，完全不取函数地址  
  证据：`vendor/linux-framework/kernel/bpf/verifier.c:3524-3541`

因此，**“用 kfunc infra 实现”只能推出 registration path 被复用，不能推出 semantic abstraction 没有新东西**。

### 3.2 如果将来统一到 kfunc 路径，也不等于 kinsn 不需要独立存在

即使把 `PSEUDO_KINSN_CALL` 统一编码到 `PSEUDO_KFUNC_CALL`，只要下面三样还在，`kinsn` 仍是独立抽象：

1. sidecar payload transport
2. proof-lowering verifier path
3. native emit dispatch

换句话说，**可以统一 plumbing，但不能消掉 abstraction**。  
消掉这三样之后，剩下的才只是“普通 kfunc 调用”。

---

## 4. verifier 本质差异：普通 kfunc 是黑盒 call，kinsn 是 proof-visible instruction

## 4.1 普通 kfunc：verifier 不看函数体，只看原型/flags

普通 `kfunc` 的元数据来自：

- BTF function prototype
- kfunc flags
- 允许性检查

证据：

- `fetch_kfunc_meta()` 从 BTF 取 `func_proto`、`func_name`、`kfunc_flags`：`vendor/linux-framework/kernel/bpf/verifier.c:3405-3449`
- `fetch_kfunc_arg_meta()` 只把 `btf/proto/name/flags` 填入 `meta`：`vendor/linux-framework/kernel/bpf/verifier.c:14203-14226`
- `check_kfunc_args()` 逐个参数按 BTF 类型做检查：`vendor/linux-framework/kernel/bpf/verifier.c:13656-14120`
- 返回值按 BTF 返回类型建模：`vendor/linux-framework/kernel/bpf/verifier.c:14650-14779`
- 调用后统一 clobber caller-saved regs：`vendor/linux-framework/kernel/bpf/verifier.c:14643-14648`

普通 `kfunc` descriptor 里保存的是：

```c
struct bpf_kfunc_desc {
	struct btf_func_model func_model;
	const struct bpf_kinsn *kinsn;
	u32 func_id;
	s32 imm;
	u16 offset;
	unsigned long addr;
};
```

证据：`vendor/linux-framework/kernel/bpf/verifier.c:3180-3187`。

对普通 `kfunc`，最终被填充的是 `addr` 和 `func_model`，而不是 `kinsn`：

- `addr = kallsyms_lookup_name(kfunc.name)`  
- `btf_distill_func_proto(..., &func_model)`  
- `desc->addr = addr; desc->func_model = func_model;`

证据：`vendor/linux-framework/kernel/bpf/verifier.c:3542-3566`，`vendor/linux-framework/kernel/bpf/btf.c:7485-7553`。

这说明普通 `kfunc` 的 verifier 视角始终是：“这是一个黑盒函数调用；我只知道签名，不知道函数体。”

## 4.2 kinsn：verifier 真正验证的是 instantiated proof sequence

`kinsn` 走的是完全不同的路径：

1. `add_subprog_and_kfunc()` 识别 `BPF_PSEUDO_KINSN_CALL`，统计 `env->kinsn_call_cnt`，并以 `kinsn_call=true` 注册 descriptor。  
   证据：`vendor/linux-framework/kernel/bpf/verifier.c:3928-3963`

2. `lower_kinsn_proof_regions()` 在主 verifier 之前，把每个 `sidecar + kinsn_call` 替换成 `instantiate_insn(payload)` 生成的 proof sequence。  
   证据：`vendor/linux-framework/kernel/bpf/verifier.c:3723-3835`

3. verifier 随后对 lowered 程序跑标准流程：`check_subprogs()`、`check_cfg()`、`compute_postorder()`、`compute_scc()`、`compute_live_registers()`、`do_check_main()`、`do_check_subprogs()`。  
   证据：`vendor/linux-framework/kernel/bpf/verifier.c:26408-26484`

4. 验证成功后，再 `restore_kinsn_proof_regions()` 把 proof sequence 恢复回原始 sidecar+call transport。  
   证据：`vendor/linux-framework/kernel/bpf/verifier.c:3837-3879`，`vendor/linux-framework/kernel/bpf/verifier.c:26479-26484`

还要注意两条非常强的证据：

- verifier 明确禁止“未 lowering 的 kinsn call”继续走普通 call 检查：  
  `internal error: kinsn call reached verifier without proof lowering`  
  证据：`vendor/linux-framework/kernel/bpf/verifier.c:21474-21476`

- `check_kinsn_sidecar_insn()` 只做 transport 完整性检查，要求 sidecar 后面必须立刻跟 kinsn call。  
  证据：`vendor/linux-framework/kernel/bpf/verifier.c:21355-21372`

所以，**当前 tree 中 kinsn 的 verifier 语义来源不是 call rule，而是 proof-lowering 后的 ordinary BPF**。  
这已经足以把它和普通 `kfunc` 区分开。

## 4.3 这比“普通 kfunc + emit callback”多了什么？

多出来的是：**call 站点不再被 verifier 当作 opaque function invocation，而被当作一个可以展开、验证、恢复的 instruction-form object。**

这正是 reviewer 质疑中的关键误区。  
如果只是“普通 kfunc + emit callback”，verifier 侧仍然会停留在 `check_kfunc_call()` 这条黑盒语义路径上。  
当前 `kinsn` 不是这样；它有一整条独立的 proof-lowering verifier path。

## 4.4 需要诚实加上的一个 caveat

如果按你最初的 `bpf_kinsn_effect` 说法，结论会更强：module 只能声明 effect，core verifier 强制执行 effect。  
**但这不是当前 tree 的实现。**

当前 tree 的真实安全叙述应更精确地写成：

- **BPF-visible safety** 来自 ordinary-BPF proof sequence 的标准 verifier；
- **native correctness** 额外依赖 `emit_x86/emit_arm64` 对 `instantiate_insn()` 的 refinement。

也就是说，当前 tree 确实比普通 `kfunc` 更“可验证”，但它的 novelty 是 **proof-visible instruction semantics**，不是更强的 **effect-DSL trust narrowing**。

---

## 5. 抽象层级差异：函数调用 vs 指令形式

## 5.1 普通 kfunc 仍然是 call ABI

普通 BPF call 的 helper/kfunc 原型是固定走寄存器 ABI 的：`func(u64 r1, u64 r2, u64 r3, u64 r4, u64 r5)`。  
证据：`vendor/linux-framework/include/linux/bpf.h:924-965`。

如果把一个局部 peephole 重写成普通 `kfunc`，即便语义上可行，也仍然要承担：

- 参数搬运到 R1-R5
- runtime `call` / `ret`
- 返回值从 R0 再搬回目标寄存器
- caller-saved clobber 语义

这仍然是**函数级**抽象。

## 5.2 kinsn transport 是专用 instruction form

daemon 发出的 kinsn 不是普通 call，而是：

1. `BpfInsn::kinsn_sidecar(payload)`
2. `BpfInsn::call_kinsn_with_off(btf_id, off)`

证据：`daemon/src/passes/utils.rs:281-292`，`daemon/src/insn.rs:243-290`。

payload 直接编码：

- 结果寄存器
- 输入寄存器
- offset
- 立即数参数

因此，**operand/result placement 是 payload-level，而不是 ABI-level**。

`emit_packed_kinsn_call_with_off()` 的注释甚至明确写了：

> “The result register is part of `payload`, so no extra `mov dst, r0` is emitted here.”

证据：`daemon/src/passes/utils.rs:281-292`。

这就是为什么它是 instruction abstraction，而不是 function abstraction。

## 5.3 具体 pass 里，替换粒度就是 instruction-form 粒度

### rotate

- 识别的是 `MOV provenance + RSH + LSH + OR` 窗口  
  证据：`daemon/src/passes/rotate.rs:239-360`
- `old_len = (pc + 3) - mov_pc`，即典型 4→2 BPF transport 替换  
  证据：`daemon/src/passes/rotate.rs:294-309`
- native emit 不是函数调用，而是 x86 `mov + rol` 或 ARM64 `EXTR`  
  证据：`module/x86/bpf_rotate.c:95-125`，`module/arm64/bpf_rotate.c:68-95`

### cond_select

- 识别 4-insn diamond 或 3-insn short pattern  
  证据：`daemon/src/passes/cond_select.rs:327-411`
- `old_len` 分别为 4 或 3  
  证据：`daemon/src/passes/cond_select.rs:361`，`daemon/src/passes/cond_select.rs:411`
- native emit 是 x86 `test + cmov` 或 ARM64 `tst + csel`  
  证据：`module/x86/bpf_select.c:102-146`，`module/arm64/bpf_select.c:71-105`

### extract

- 识别 `RSH + AND` 两条指令  
  证据：`daemon/src/passes/extract.rs:55-94`
- `old_len = 2`，替换成 2-insn transport  
  证据：`daemon/src/passes/extract.rs:77-83`，`daemon/src/passes/extract.rs:196-200`
- native emit 是直接内联 bitfield extract sequence，而不是 helper body call  
  证据：`module/x86/bpf_extract.c:96-127`，`module/arm64/bpf_extract.c:64-90`

### endian_fusion

- 识别 `LDX_MEM + ENDIAN_TO_BE`  
  证据：`daemon/src/passes/endian.rs:17-33`，`daemon/src/passes/endian.rs:53-107`
- 直接把 offset 编进 payload；必要时也只是在 packed transport 周围补地址物化，而不是切回 legacy call ABI  
  证据：`daemon/src/passes/endian.rs:155-210`
- 注释明确说“instead of using any legacy call ABI”  
  证据：`daemon/src/passes/endian.rs:30-33`

### bulk_memory

- 识别大段 scalarized memcpy/memset  
  证据：`daemon/src/passes/bulk_memory.rs:92-93`
- `MIN_BULK_BYTES = 32`，`CHUNK_MAX_BYTES = 128`  
  证据：`daemon/src/passes/bulk_memory.rs:12-18`
- 每个 chunk 仅发出 `2` 条 transport 指令  
  证据：`daemon/src/passes/bulk_memory.rs:529-547`，`daemon/src/passes/bulk_memory.rs:557-573`
- verifier proof sequence 却可以展开为最多 `128*2` 条 bytewise memcpy 指令  
  证据：`module/x86/bpf_bulk_memory.c:131-150`，`module/x86/bpf_bulk_memory.c:449-455`

这类“**大窗口 -> 单个逻辑指令 -> 小 native 序列**”的替换，正是普通 `kfunc` 难以等价替代的地方。

---

## 6. 优雅降级：这也是普通 kfunc 不具备的产品级属性

## 6.1 module 没加载时，daemon 直接保持原始 bytecode

discovery 阶段如果 `/sys/kernel/btf/<module>` 不存在，就把该 target 标成 unavailable：

- `module '<name>' not loaded (no BTF at ...)`
- 对应 `registry.*_btf_id` 保持 `-1`

证据：`daemon/src/kfunc_discovery.rs:311-381`。

各 pass 在发现 target 不可用时，直接 `changed=false` 返回，不改原程序：

- rotate：`daemon/src/passes/rotate.rs:29-41`
- cond_select：`daemon/src/passes/cond_select.rs:143-171`
- extract：`daemon/src/passes/extract.rs:111-138`
- endian_fusion：`daemon/src/passes/endian.rs:228-266`
- bulk_memory：`daemon/src/passes/bulk_memory.rs:151-175`

这意味着 **module 缺失不会导致应用程序不能运行，只会让优化 pass 不生效**。

## 6.2 module 存在但当前架构/后端没有 native emit 时，kernel 回退到 proof sequence

在 `do_misc_fixups()` 里：

- 若 `prog->jit_requested && bpf_kinsn_has_native_emit(kinsn)`，保留 sidecar+call 给 JIT 原生发码；
- 否则，就把 sidecar+call 替换成 `instantiate_insn()` 生成的 proof sequence。

证据：`vendor/linux-framework/kernel/bpf/verifier.c:23755-23795`。

所以 kinsn 有两层 graceful degradation：

1. **用户态 pass 层**：没发现 module，就不改写
2. **内核 JIT 层**：发现了 kinsn 但没 native emit，也还能退回 ordinary BPF

这比“硬依赖某个 kfunc 必须存在，否则 load fail”更平滑。

---

## 7. “纯用 kfunc 能不能做出同样效果？”答案是：不能等价复制当前实现的关键性质

## 7.1 代码已经表明这些 pass 依赖的是 packed kinsn，而不是普通 kfunc

当前真正使用 `emit_packed_kinsn_call_with_off()` 的 pass 一共有 5 个：

1. `bulk_memory`
2. `rotate`
3. `cond_select`
4. `extract`
5. `endian_fusion`

证据：

- `daemon/src/passes/bulk_memory.rs`
- `daemon/src/passes/rotate.rs`
- `daemon/src/passes/cond_select.rs`
- `daemon/src/passes/extract.rs`
- `daemon/src/passes/endian.rs`

这些 pass 发出的都是 `BPF_PSEUDO_KINSN_CALL`，不是 `BPF_PSEUDO_KFUNC_CALL`。  
证据：`daemon/src/passes/utils.rs:281-292`，以及各 pass 的 replacement 构造代码。

## 7.2 某些 pass 明确拒绝回退到 legacy call ABI

最清楚的是 `endian_fusion` 和 `cond_select`：

- `endian_fusion` 注释明确说，即便 offset 不能直接编码，也是在 packed transport 周围补地址计算，**“instead of using any legacy call ABI”**。  
  证据：`daemon/src/passes/endian.rs:30-33`

- `cond_select` 如果 true/false 不是寄存器值，就直接 skip，原因是 packed path 需要 register operands；它没有实现任何“普通 kfunc ABI fallback”。  
  证据：`daemon/src/passes/cond_select.rs:104-111`，`daemon/src/passes/cond_select.rs:227-233`

这不是偶然，而是实现者明确在说：**纯 kfunc ABI 不是这个抽象想要的东西。**

## 7.3 普通 kfunc 只能给你“call 一个函数”，而不是“在 bytecode 中保留一个 instruction site”

如果没有 `kinsn`，你最多能做到：

- 把 peephole pattern 改写成普通 `kfunc` 调用；
- 希望 JIT 再特殊识别这个 call 去做 inline emit。

但这样依然缺 3 个核心能力：

1. verifier 不会把它当 proof-visible instruction，只会走黑盒 call rule；
2. bytecode 中没有独立的 sidecar payload instruction form；
3. daemon 无法在不占用 R1-R5 ABI 的情况下，把 dst/src/off 等局部语义原样保留到后端。

换言之，**没有 kinsn，你可以伪装出“可 inline 的函数调用”；但你得不到“可验证、可恢复、可携带 operand payload 的指令形式”。**

---

## 8. 量化：当前仓库里到底有多少优化依赖 kinsn？

`PASS_REGISTRY` 一共注册了 12 个 pass：  
证据：`daemon/src/passes/mod.rs:52-118`

其中 **5 个直接依赖 kinsn packed transport**：

1. `bulk_memory`
2. `rotate`
3. `cond_select`
4. `extract`
5. `endian_fusion`

其余 **7 个是纯 bytecode 变换，不依赖 kinsn**：

1. `map_inline`
2. `const_prop`
3. `dce`
4. `skb_load_bytes_spec`
5. `bounds_check_merge`
6. `wide_mem`
7. `branch_flip`

特别是 `wide_mem` 的注释写得很直白：

> “No kinsn support needed -- pure BPF replacement.”

证据：`daemon/src/passes/wide_mem.rs:380-385`。

因此，从现有实现看：

- **kinsn 不是整个系统的必要条件**；
- 但它确实支撑了一组独立的、不可用纯 bytecode pass 替代的指令级 peephole 优化；
- reviewer 如果问 “到底多了什么新能力”，答案不是“所有优化都靠 kinsn”，而是“**某一类 instruction-form peephole optimization 需要它**”。

## 8.1 静态替换规模

| pass | 典型原始窗口 | BPF transport | native emit |
| --- | --- | --- | --- |
| rotate | 4 insns | 2 insns | x86 `mov+rol` / ARM64 `EXTR` |
| cond_select | 3 或 4 insns | 2 insns | x86 `test+cmov` / ARM64 `tst+csel` |
| extract | 2 insns | 2 insns | x86 inline extract seq / ARM64 `UBFM` |
| endian_fusion | 2 insns | 2 insns（少数场景 3-4） | x86 load+bswap / ARM64 load+REV |
| bulk_memory | 32B~128B 的长 store/load run | 每 chunk 2 insns | x86 `rep movsb/stosb` 或 ARM64 pair-loop |

这张表的重点不是所有 case 都是“N→1 machine insn”，而是：

- `kinsn` 把局部优化机会保留成一个独立的 instruction site；
- JIT 再把它降为短 native 序列；
- 中间没有普通函数调用 ABI 的寄存器搬运与 runtime call。

---

## 9. 给 reviewer 的直接回答

可以把回应压缩成下面这段：

> `kinsn` 复用了 `kfunc` 的注册与发现 plumbing，但它不是普通 `kfunc` 的语义别名。普通 `kfunc` 在 verifier 中是黑盒函数调用，安全模型只基于 BTF prototype 和 flags；当前 `kinsn` 则在主 verifier 之前被 lower 成 ordinary-BPF proof sequence，verifier 真正验证的是这段展开后的 BPF 语义，然后再把 site 恢复成原始 `sidecar + PSEUDO_KINSN_CALL` transport。JIT 阶段，普通 `kfunc` 仍是 runtime call 到 kernel symbol，而 `kinsn` 则根据 payload 直接内联 native code。因此，`kinsn` 的 novelty 不在于“又发明了一条注册 API”，而在于它把目标相关 peephole 优化提升成一种 verifier-visible、bytecode-carried、可原生发码又可回退 proof sequence 的 instruction-form abstraction。没有 kinsn，最多只能得到一个可 inline 的函数调用；得不到当前这种带 sidecar payload、proof-lowering、native emit dispatch 的独立指令抽象。`

---

## 10. 对论文措辞的建议

基于当前代码树，建议正文避免再使用下面这些说法：

- “`bpf_kinsn_effect` 是当前实现”
- “module 只声明 effect，core verifier 强制执行 effect”
- “当前 in-tree novelty 主要来自 declarative effect DSL”

更准确的表述应该是：

1. **当前实现的 novelty**：proof-visible instruction form + packed sidecar transport + native emit refinement + graceful degradation。
2. **不是 novelty 的部分**：kfunc registration plumbing 复用。
3. **如果想讨论 effect DSL**：应明确写成 future design / stronger design point，而不是 current implementation。

否则 reviewer 很容易抓住“文字说的是 effect DSL，代码实现其实是 proof-lowering”这一点。

---

## 11. 最终判断

如果严格基于当前代码树，我的结论是：

- **“kinsn 只是 kfunc + emit callback”这个说法不成立。**
- 但 **“kinsn 的 novelty 来自 declarative effect DSL”这个说法在当前 tree 也不成立。**

当前 tree 能站得住脚的 novelty，是：

1. **专用 bytecode transport**：`sidecar + PSEUDO_KINSN_CALL`
2. **独立 verifier 语义**：proof-lowering，而非黑盒 call
3. **独立 JIT 语义**：descriptor-driven native inline emit，而非 runtime symbol call
4. **双层 graceful degradation**：daemon 不改写 / kernel proof fallback

如果第 3 节按这个版本重写，reviewer 的质疑可以被正面化解；  
如果继续把当前实现写成 `bpf_kinsn_effect` 式的 effect DSL，就会留下明显的可攻击点。


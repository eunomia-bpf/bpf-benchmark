# kinsn v2 简化设计文档

日期：2026-03-23

主题：`instantiate_insn()` 方案

基线代码：

- `docs/kinsn-design.md`
- `docs/kernel-jit-optimization-plan.md` §4.4、行 417-420，以及行 176 的现状备注
- `vendor/linux-framework/include/linux/bpf.h`
- `vendor/linux-framework/include/uapi/linux/bpf.h`
- `vendor/linux-framework/include/linux/bpf_verifier.h`
- `vendor/linux-framework/kernel/bpf/verifier.c`
- `vendor/linux-framework/kernel/bpf/core.c`
- `vendor/linux-framework/kernel/bpf/disasm.c`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c`
- `module/include/kinsn_common.h`
- `module/x86/bpf_rotate.c`
- `module/x86/bpf_select.c`
- `module/x86/bpf_extract.c`
- `module/x86/bpf_endian.c`
- `module/x86/bpf_barrier.c`
- `daemon/src/insn.rs`
- `daemon/src/passes/utils.rs`
- `daemon/src/pass.rs`
- `daemon/src/passes/{rotate,extract,cond_select,endian,spectre}.rs`

---

## 1. 当前 v1 的真实基线

当前实现不是“新 opcode”，而是：

1. 一条 sidecar pseudo-insn：

```c
(struct bpf_insn) {
    .code    = BPF_ALU64 | BPF_MOV | BPF_K,
    .src_reg = BPF_PSEUDO_KINSN_SIDECAR,
    .dst_reg/off/imm = payload bits,
}
```

2. 紧跟一条 `PSEUDO_KFUNC_CALL`：

```c
(struct bpf_insn) {
    .code    = BPF_JMP | BPF_CALL,
    .src_reg = BPF_PSEUDO_KFUNC_CALL,
    .off     = module BTF fd slot,
    .imm     = kfunc BTF id,
}
```

verifier 侧真实流程在 `check_kinsn_call()` 中：

1. 找 sidecar。
2. `bpf_prepare_kinsn_call()` 统一解码成 `struct bpf_kinsn_call`。
3. `validate_call()`。
4. packed ABI 走 `check_kinsn_encoded_operands()`。
5. `bpf_collect_kinsn_scalar_inputs()` 收集输入标量摘要。
6. `model_call()` 生成声明式 `struct bpf_kinsn_effect`。
7. `bpf_validate_kinsn_effect()` / `bpf_kinsn_check_input_regs()` /
   `bpf_kinsn_check_mem_accesses()` /
   `bpf_kinsn_apply_clobber_mask()` /
   `bpf_kinsn_apply_result()` /
   `bpf_kinsn_apply_subreg_def()`。

JIT 侧真实流程在 x86 `emit_kinsn_call()` 中：

1. `bpf_jit_find_kinsn_ops()` 找 `desc->kinsn_ops`
2. `bpf_jit_get_kinsn_call()` 再解码一次
3. 调 `ops->emit_x86()`
4. 校验返回字节数与 `max_emit_bytes`

现有 verifier 中与 kinsn effect/apply 直接相关的逻辑大约是：

- `verifier.c:14388-14844`，457 行
- `verifier.c:3733-3865`，133 行
- `verifier.c:21804-21831`，28 行 sidecar 检查

现有 x86 JIT 的专用 dispatch：

- `arch/x86/net/bpf_jit_comp.c:579-603`，25 行 `emit_kinsn_call()`

当前 5 个 x86 kinsn module 都遵循同一模式：

- `decode_call`
- `validate_call`
- `model_call`
- `emit_x86`

其中：

- `rotate` / `extract` / `select` / `endian` 都有 packed payload decode
- `barrier` 只要求 payload 为 0
- `endian` 是唯一真正的 memory kinsn
- `barrier` 的本质语义已经有现成 BPF 等价物：`BPF_ST_NOSPEC()`

---

## 2. v1 vs v2 对比

| 维度 | v1：`model_call + effect` | v2：`instantiate_insn + walk` | 结论 |
| --- | --- | --- | --- |
| verifier core 改动量 | 已经落地，公共逻辑较重。`effect` 校验/应用和 memory 特判都在 core。新增 kinsn 时 core 不改，但初始机制本身不小。 | 如果只看“每个 kinsn 的验证语义”，core 会明显变小：不再需要 `collect_scalar_inputs` / `validate_effect` / `apply_*`。但如果同时引入“全新非-kfunc call 类型”，会新增一批跨 `verifier/core/disasm/JIT/UAPI` 的改动。 | `instantiate` 本身简化 core；“新 call 类型”会把一部分简化收益吃回去。 |
| module 复杂度 | module 需要维护一套 effect DSL：输入 mask、clobber mask、result range/tnum、mem_access。 | module 只需要能把 payload 展开成小段等价 BPF 指令，再保留一个 native `jit_emit`。 | 对当前 5 个 kinsn，v2 更自然。 |
| 代码膨胀 | 用户字节码是 `sidecar + call` 两条；verifier/JIT 不需要内部展开指令流。 | 用户字节码仍可保持两条，但 verifier 和 JIT fallback 需要看到 0-5 条左右的“内部展开序列”。 | 外部 bytecode 不必膨胀，内部分析/翻译会膨胀。 |
| 安全模型 | module 不能碰 `bpf_reg_state`，只能报 effect；core 统一 apply。 | module 不能碰 `bpf_reg_state`，但可以生成一段 BPF 语义程序；安全性来自“这段程序再被 verifier 按普通 BPF 校验”。 | v2 更像“把 DSL 变成真实 BPF”，模型更直接。 |
| verifier 精度 | 精度靠 module 的 `model_call()`；`extract/select/endian` 目前专门维护了 range/tnum/mem result。 | 精度来自展开后的真实 BPF 指令。`extract`、`select`、`endian` 基本都能直接落到现有 verifier 逻辑。 | 对当前 5 个例子，精度预期不差，甚至更稳定。 |
| 可扩展性 | 对“有 native 语义但不好写成 BPF 指令流”的 kinsn 也能建模，只要 effect 可描述。 | 只适合“能被小段 BPF 语义等价表达”的 kinsn。 | v2 更适合 rotate/select/extract/endian/barrier；不如 v1 通吃。 |
| JIT fallback | 当前没有“emit 失败后翻译等价 BPF 指令序列”的通用路径。 | 天然有 fallback：`jit_emit` 失败时翻译 `insn_buf`。 | v2 在多架构降级上更漂亮。 |
| daemon 耦合 | 当前 daemon 紧耦合 kfunc 发现、module fd slot、`PSEUDO_KFUNC_CALL`。 | 如果只换 verifier 语义而保留编码，daemon 几乎不动。若连 call 类型和目标对象都换，daemon 并非零改动。 | 需要把“instantiate”与“新 call ABI”拆开看。 |

一句话总结：

- **v2 的核心价值在 `instantiate_insn()`，不在“必须改成全新 call 编码”。**
- **如果把“instantiate”与“新 non-kfunc call ABI”绑在一起，迁移面会明显变大。**

---

## 3. v2 完整设计

### 3.1 设计目标

目标不是让 module 直接操作 verifier state，而是把 module 的“验证语义”从一套自定义 effect DSL，改成一小段 verifier 本来就懂的 BPF 指令。

约束建议：

1. sidecar payload 继续保留。
2. `instantiate_insn()` 返回的序列必须是小型、有限、无 back-edge 的局部 BPF CFG。
3. 不允许在展开序列里再嵌套 helper/kfunc/kinsn/tailcall/subprog call。
4. JIT native path 和 fallback path 必须共享同一个 payload decode 约定。
5. 现阶段以“覆盖当前 5 个 x86 kinsn”为目标，不强行为 future SIMD 类 kinsn 过度设计。

### 3.2 推荐的 `struct bpf_kinsn`

从当前代码看，`src/dst/imm` 三元组不够通用：

- `select` 需要 3 个寄存器和 1 个 condition code nibble
- `extract` 需要两个 imm8
- `endian` 只有 `dst/base`
- `barrier` 没有操作数

因此更稳妥的接口是直接传 raw payload，而不是把 payload 再硬拆成“统一的 `src/dst/imm`”。

建议定义：

```c
struct bpf_kinsn {
    struct module *owner;
    u16 api_version;
    u16 max_insn_cnt;     /* verifier/JIT fallback 分配 insn_buf 上界 */
    u16 max_emit_bytes;   /* native emit 上界，沿用 v1 语义 */

    /*
     * 输入：sidecar raw payload
     * 输出：insn_buf[0..nr-1]
     * 返回：nr_insns 或负 errno
     */
    int (*instantiate_insn)(u64 payload, struct bpf_insn *insn_buf);

    int (*emit_x86)(u8 *image, u32 *off, bool emit,
                    u64 payload, struct bpf_prog *prog);
    int (*emit_arm64)(u32 *image, int *idx, bool emit,
                      u64 payload, struct bpf_prog *prog);
};
```

说明：

- `max_insn_cnt` 是上界，不是固定条数。
- `instantiate_insn()` 自带 payload decode 和 payload validation。
- 对当前 5 个 x86 kinsn，`emit_x86()` 基本可以直接复用现有 `emit_*_x86()` 的主体，只是输入从 `struct bpf_kinsn_call` 变成 `u64 payload`。

如果一定要保留最初 sketch 的签名：

```c
int (*instantiate_insn)(u32 src, u32 dst, u64 imm, struct bpf_insn *insn_buf);
```

那本质上还是要先把 raw payload decode 成一组更复杂的局部结构，`select/endian/extract` 并不会因此更简单。所以不建议把公共 API 固定成 `src/dst/imm`。

### 3.3 编码格式

#### 3.3.1 sidecar

sidecar 建议保持完全不变：

```c
(struct bpf_insn) {
    .code    = BPF_ALU64 | BPF_MOV | BPF_K,
    .src_reg = BPF_PSEUDO_KINSN_SIDECAR,
    .dst_reg/off/imm = payload bits,
}
```

理由：

- 当前 daemon 已经统一会发它
- 当前 payload 布局已经覆盖 5 个 x86 kinsn
- `bpf_kinsn_sidecar_payload()` 与 daemon `BpfInsn::kinsn_sidecar()` 已经一致

#### 3.3.2 第二条 call

用户提出的 clean-slate 版本是：

```c
(struct bpf_insn) {
    .code    = BPF_JMP | BPF_CALL,
    .src_reg = BPF_PSEUDO_KINSN_CALL,
    .off     = module_btf_fd_slot_or_0,
    .imm     = kinsn_target_btf_id,
}
```

这里有两个关键点：

1. **`off` 最好不要废掉。**

   当前 module kfunc 之所以把 `CALL.off` 留给 module fd slot，是因为 module BTF id 只在各自 BTF 对象里唯一。  
   如果 v2 target 仍在 module BTF 里，`off = fd_slot` 这个命名空间问题依然存在。

2. **`imm` 对什么做索引，有两个可行子方案。**

   方案 A：`imm` 继续指向“现有 kfunc 名字/BTF func id”，kernel 内部把这个符号映射到 `struct bpf_kinsn *`  
   优点：daemon 发现逻辑最小改动。  
   缺点：抽象上仍借用了 kfunc 名字。

   方案 B：`imm` 改成“导出的 `struct bpf_kinsn` descriptor 的 BTF id”  
   优点：抽象更纯。  
   缺点：daemon 发现逻辑、kernel lookup 路径都要重做。

**结论：**

- 如果目标是“论文前快速收敛”，建议优先用 **方案 A**。
- 如果目标是“长期抽象纯度”，可以后续演进到 **方案 B**。

### 3.4 verifier 流程

目标流程：

1. 跳过 sidecar 本身。
2. 在 call 处解析出 raw payload 和目标 `struct bpf_kinsn *`。
3. 分配 `insn_buf[max_insn_cnt]`。
4. 调 `instantiate_insn(payload, insn_buf)`，得到 `nr_insns`。
5. 对 `insn_buf[0..nr_insns-1]` 逐条复用现有 verifier 指令检查逻辑。
6. 用展开后得到的最终寄存器/栈状态替代原始 kinsn call 的结果状态。

建议新增一个小 helper，例如：

```c
static int check_kinsn_inst_seq(struct bpf_verifier_env *env,
                                const struct bpf_insn *insn_buf,
                                u32 nr_insns);
```

这个 helper 应该强制这些限制：

1. 只允许局部展开，不允许再出现 helper/kfunc/kinsn/subprog call。
2. 不允许 `EXIT`。
3. 允许条件跳转，但只允许跳到 `insn_buf` 内部，且不允许 back-edge。
4. 不允许 sidecar pseudo-insn。
5. 允许普通栈 spill/fill、`LDX`、`STX`、`ALU/ALU64`、`MOV`、`END`、`ST_NOSPEC`。

这样做以后，以下 v1 专用逻辑可以删除：

- `model_call()`
- `bpf_collect_kinsn_scalar_inputs()`
- `bpf_validate_kinsn_effect()`
- `bpf_kinsn_check_input_regs()`
- `bpf_kinsn_check_mem_accesses()`
- `bpf_kinsn_apply_clobber_mask()`
- `bpf_kinsn_apply_result()`
- `bpf_kinsn_apply_subreg_def()`

#### 3.4.1 backtracking / aux_data

这里有一个实际实现细节：

- 如果 verifier 只是“临时 walk 一段 `insn_buf`”，而不真正把原始程序改写成展开后的程序，
- 那么后续 liveness/backtracking 仍然只看到原始 call 位点。

因此有两种做法：

1. 简单做法：保留一个精简版 `insn_aux_data` 摘要，例如从展开序列自动推导 `clobber_mask`
2. 更彻底的做法：在 verifier 内部维护一份“展开后的临时程序视图”

对于论文前实现，我更建议 **做法 1**：

- 继续保留一个很小的 call-site summary
- 但这个 summary 不是 module 声明出来的，而是从 instantiated BPF 序列机械扫描出来的

这样可以保住“verifier core 改动很小”的目标。

### 3.5 JIT 流程

建议流程：

1. JIT 在 `BPF_CALL` case 识别 `BPF_PSEUDO_KINSN_CALL`
2. 解析 payload 和目标 `struct bpf_kinsn *`
3. 如果 `emit_x86()` / `emit_arm64()` 成功：
   - 直接发 native
4. 如果 emit callback 缺失或返回 `-EOPNOTSUPP`：
   - 调 `instantiate_insn()` 生成 `insn_buf`
   - 把 `insn_buf` 当作普通 BPF 指令序列继续翻译

和 v1 相比，这里的关键变化是：

- v1：inline emit 失败就是硬失败
- v2：inline emit 失败仍有正确的 BPF fallback

这对跨架构部署是加分项。

#### 3.5.1 x86 fallback 的现实实现建议

当前 x86 JIT 是单个大 switch；如果要翻译 `insn_buf`，需要一个小包装层把“单条 BPF 指令 emit”抽出来。

对当前 5 个 x86 kinsn，fallback 用到的 BPF 子集其实很小：

- `MOV`
- `ALU64 {LSH,RSH,OR,AND,ADD}`
- `LDX_MEM`
- `BPF_END`
- `JMP {JEQ,JNE,JA}`
- `BPF_ST_NOSPEC`

因此不需要先做一个“完整 mini-JIT for arbitrary BPF”；
做一个只服务于 instantiated kinsn 的局部 translator 就够了。

### 3.6 临时寄存器处理策略

推荐策略：

1. 先根据 payload 得到 `explicit_reg_mask`
2. 在 `r0-r9` 中选一个不在 mask 内、且不是 `r10` 的临时寄存器
3. 优先不 spill；只有 future kinsn 真遇到所有候选都占满时，再退化到栈 spill/fill

对当前 5 个 x86 kinsn：

- `rotate` 需要 1 个 temp
- `select` 可以用 branch 版本，0 temp
- `extract` 不需要 temp
- `endian` 不需要 temp
- `barrier` 不需要 temp

所以 **当前 5 个例子实际上不需要“强制实现 stack spill/fill 才能落地”**。

这点很重要，因为它意味着 v2 首版可以先不引入复杂的“隐式临时栈槽协议”。

---

## 4. 5 个 kinsn 的 `instantiate_insn()` 示例

下面都以“继续复用当前 packed payload 布局”为前提。

### 4.1 `bpf_rotate64`

当前 payload：

```text
dst[3:0] | src[7:4] | shift[15:8]
```

建议展开：

```c
tmp = choose_unused_reg(dst, src);

if (shift == 0) {
    if (dst != src)
        MOV64 dst, src;
    return nr;
}

MOV64 tmp, src;
if (dst != src)
    MOV64 dst, src;
LSH64_IMM dst, shift;
RSH64_IMM tmp, 64 - shift;
OR64 dst, tmp;
```

说明：

- 这正好对应当前 x86 native emit 的 `mov + rol`
- verifier 会把它当普通 shift/or 序列分析
- 当前 `rotate` 的 `model_call()` 本来也没有提供额外 tnum/range 精度，所以 v2 不吃亏

### 4.2 `bpf_select64`

当前 payload：

```text
dst[3:0] | true[7:4] | false[11:8] | cond[15:12] | cc[19:16]
```

当前只有 `cc == 0`，语义是 `cond != 0 ? true : false`。

建议用无 temp、局部 branch 的形式展开：

1. `dst == false_reg`

```c
JEQ cond, 0, +1;
MOV64 dst, true_reg;
```

2. `dst == true_reg`

```c
JNE cond, 0, +1;
MOV64 dst, false_reg;
```

3. `dst` 与两者都不同

```c
MOV64 dst, false_reg;
JEQ cond, 0, +1;
MOV64 dst, true_reg;
```

说明：

- 这能避免临时寄存器
- verifier 现有 branch merge 就能自然得到“true/false 两路 union”的结果
- 当前 `model_select_call()` 里那段 `union_scalar_states()` 可以删掉

### 4.3 `bpf_extract64`

当前 payload：

```text
dst[3:0] | start[15:8] | len[23:16]
```

建议展开：

```c
if (start != 0)
    RSH64_IMM dst, start;
AND64_IMM dst, mask(len);
```

其中：

- `len == 32` 时 `mask = 0xffffffff`
- 其余是 `(1U << len) - 1`

说明：

- 当前 packed x86 emit 本来就是 `shr + and`
- verifier 对 `RSH` 和 `AND` 已有成熟的范围/tnum 缩窄逻辑
- 所以当前 `model_extract_call()` 的区间推导基本可以被展开序列替代

### 4.4 `bpf_endian_load16/32/64`

当前 payload：

```text
dst[3:0] | base[7:4]
```

建议展开：

1. `load16`

```c
LDX_MEM(H) dst, [base + 0];
BPF_ENDIAN(BPF_FROM_BE, dst, 16);
```

2. `load32`

```c
LDX_MEM(W) dst, [base + 0];
BPF_ENDIAN(BPF_FROM_BE, dst, 32);
```

3. `load64`

```c
LDX_MEM(DW) dst, [base + 0];
BPF_ENDIAN(BPF_FROM_BE, dst, 64);
```

说明：

- 现有 verifier 已经懂 `LDX_MEM`
- 现有 verifier/JIT 已经懂 `BPF_END`
- 当前 x86 JIT 对 `BPF_END` 直接发 `ror16/bswap32/bswap64`

#### 关于 offset

当前 daemon 的 `endian` pass 对非零 offset 已经会：

- 临时 `ADD` base
- 发 `sidecar + call`
- 再 `SUB` 回去

所以 v2 第一版完全可以继续沿用这个行为，不必马上改 payload。

如果后续要继续简化 daemon，可把 sidecar 里空余 bit 用于编码 `s16 off`，再让 `instantiate_insn()` 自己展开成：

```c
tmp = choose_unused_reg(...);
MOV64 tmp, base;
ADD64_IMM tmp, off;
LDX_MEM size, dst, [tmp + 0];
ENDIAN dst;
```

但这不是首版必需项。

### 4.5 `bpf_speculation_barrier`

当前 payload：

```text
0
```

建议展开成现成 BPF 内部指令：

```c
BPF_ST_NOSPEC();
```

这点非常关键。

因为当前 kernel 里：

- `include/linux/filter.h` 已有 `BPF_ST_NOSPEC()`
- `kernel/bpf/core.c` 已有解释器语义
- `arch/x86/net/bpf_jit_comp.c` 已直接把它翻成 `lfence`

所以 `barrier` 在 v2 下不是“空展开”，而是有真实 BPF 等价物。

这意味着：

- verifier 不需要任何 special modeling
- JIT fallback 也不会丢掉 Spectre barrier 语义

---

## 5. v1 -> v2 迁移评估

### 5.1 kernel 需要改什么

#### 5.1.1 `include/linux/bpf.h`

删除或废弃：

- `enum bpf_kinsn_encoding`
- `struct bpf_kinsn_call`
- `struct bpf_kinsn_operand`
- `struct bpf_kinsn_scalar_state`
- `struct bpf_kinsn_effect`
- `struct bpf_kinsn_mem_access`
- `struct bpf_kinsn_ops`

新增：

- `struct bpf_kinsn`
- 新的注册/查找 API
- 如采用 clean-slate ABI，再加 `BPF_PSEUDO_KINSN_CALL`

#### 5.1.2 `include/uapi/linux/bpf.h`

如果真的换 call 类型，需要新增：

```c
#define BPF_PSEUDO_KINSN_CALL <new value>
```

这不是 verifier 单文件改动，而是 UAPI 变更。

#### 5.1.3 `kernel/bpf/verifier.c`

可以删除的核心 v1 逻辑：

- `bpf_prepare_kinsn_call()` 这一整套 `bpf_kinsn_call` decode 路径
- `bpf_collect_kinsn_scalar_inputs()`
- `bpf_validate_kinsn_effect()`
- `bpf_kinsn_check_input_regs()`
- `bpf_kinsn_check_mem_accesses()`
- `bpf_kinsn_apply_clobber_mask()`
- `bpf_kinsn_apply_result()`
- `bpf_kinsn_apply_subreg_def()`
- `check_kinsn_call()` 中 `model_call()` 相关主流程

要新增的核心 v2 逻辑：

- kinsn target lookup
- `instantiate_insn()` 调用
- `check_kinsn_inst_seq()` 之类的局部 walk helper
- 可选的 call-site `aux_data` 摘要推导

如果采用 **新 non-kfunc call 编码**，还必须同步修改 verifier 里所有显式检查
`BPF_PSEUDO_KFUNC_CALL` 的位置。当前至少包括：

- `bpf_pseudo_kfunc_call()`
- `check_kinsn_sidecar_insn()`
- `do_check_insn()` 的 CALL reserved-field 验证
- `add_subprog_and_kfunc()`
- `add_kfunc_in_insns()`
- `fetch_kfunc_arg_meta()` 调用点相关路径
- `fixup_kfunc_call()` 相关后处理
- `call` 元信息/剪枝/死代码处理若干分支

也就是说，**“删除 effect 逻辑”是对的，但“verifier 改动极小”只在保留现有 call 编码时成立。**

#### 5.1.4 `include/linux/bpf_verifier.h`

如果采用“临时 walk + call-site summary”路线，`kinsn_call` / `kinsn_clobber_mask` 可以暂时保留，但语义变成：

- 不再来自 module 的 effect
- 而是来自 instantiated 序列的机械扫描

如果采用“内部真实展开后的程序视图”，这两个字段可以一起删。

#### 5.1.5 `kernel/bpf/core.c` / `kernel/bpf/disasm.c`

如果换 call 类型，需要更新：

- kinsn target address resolution
- disassembler 的 call 类型显示

这两处当前都直接认 `BPF_PSEUDO_KFUNC_CALL`。

#### 5.1.6 `arch/x86/net/bpf_jit_comp.c`

当前 x86 JIT 只是在 `CALL` case 下识别：

```c
src_reg == BPF_PSEUDO_KFUNC_CALL && bpf_jit_find_kinsn_ops(...)
```

v2 下需要改成：

1. 识别新的 kinsn call 类型
2. 做 `instantiate_insn()` fallback
3. 把局部 BPF translator 抽出来供 fallback 使用

如果未来 arm64 也要支持同一 ABI，还要同步改 `arch/arm64/net/bpf_jit_comp.c`。

### 5.2 module 需要改什么

每个 module 的变化都很明确：

- 删除 `decode_call`
- 删除 `validate_call`
- 删除 `model_call`
- 新增 `instantiate_insn`
- 保留并小改 `emit_x86`

按当前 5 个 module 看：

- `rotate`：最简单，新增一个“找 1 个 temp reg + shift/or 模板”
- `extract`：最简单，几乎直接把当前 x86 fallback 序列翻成 BPF
- `select`：用 branch 模板替代 `union_scalar_states()`
- `endian`：改成 `LDX_MEM + BPF_END`
- `barrier`：改成 `BPF_ST_NOSPEC()`

module 总体复杂度会下降，但不是“零工作”：

- 尤其是 `rotate` 需要明确 temp reg 策略
- `select` 需要小心 `dst == true/false` 的 alias 情况

### 5.3 daemon 需要改什么

这里必须分两种情况。

#### 情况 A：只换 verifier/JIT 语义，sidecar 和 call 编码基本保留

如果继续保留：

- sidecar payload 不变
- `CALL.off = module fd slot`
- `CALL.imm` 仍沿用现有 kfunc/BTF 发现路径

那 daemon 的变化可以非常小，甚至接近零：

- `emit_packed_kfunc_call_with_off()` 可以继续用，只是名字不再准确
- 五个 pass 的 payload 生成逻辑都不必改
- `ensure_module_fd_slot()` 继续保留

这是“daemon 可能基本不改”的唯一现实前提。

#### 情况 B：同时切到全新 non-kfunc call target

如果改成：

- `src_reg = BPF_PSEUDO_KINSN_CALL`
- `imm` 指向新的 kinsn descriptor，而不是当前 kfunc func id

那 daemon 不是零改动。

至少要动：

- `daemon/src/insn.rs`
- `daemon/src/passes/utils.rs`
- `daemon/src/pass.rs`
- `daemon/src/kfunc_discovery.rs`
- 五个 pass 的 call emission helper
- 对应测试

如果 descriptor 发现不再沿用当前 kfunc BTF 名字，还要重做 discovery 逻辑。

**结论：**

- “v2 daemon 不需要改”这个判断，只在“保留现有 target discovery / fd_slot 机制”时近似成立。
- 如果 full v2 连 call target 都换，daemon 改动并不小。

### 5.4 改动量估计

粗估，不是精确 diff：

#### kernel

1. 只做“instantiate 语义替换”，保留现有 sidecar + kfunc-style target path

- 删除 verifier kinsn effect/apply 逻辑：约 450-600 行
- 新增 instantiate walk + 少量 aux summary：约 150-250 行
- x86 JIT fallback translator：约 80-150 行
- 其余头文件/API 改动：约 50-100 行

这是 **中等改动量**。

2. 再叠加“新 non-kfunc call ABI”

- verifier 里所有 `PSEUDO_KFUNC_CALL` 触点都要梳理
- core/disasm/JIT/UAPI 也要改

这会把它抬到 **中到大改动量**，并且是分散式改动。

#### modules

当前 5 个 x86 module 总体在 1100 行量级。

预期改动：

- 每个 module 20-80 行净重写
- 总体约 200-350 行实质变更

这是 **小到中等改动量**。

#### daemon

1. 保留当前 target path：小改或近零改
2. 新 call ABI + 新 target discovery：中等改动，约 100-300 行以上

### 5.5 风险

1. **最大风险不是 `instantiate_insn()`，而是“新 call ABI”。**

   当前代码里 `PSEUDO_KFUNC_CALL` 触点分布在：

   - verifier
   - core
   - disasm
   - x86 JIT
   - arm64 JIT
   - daemon 发码和发现逻辑

   这是横跨多个子系统的 ABI 变化。

2. **future kinsn 的表达能力会变窄。**

   v2 很适合当前 5 个例子，但不一定适合：

   - future SIMD kinsn
   - 很难写成小段 BPF 的特殊指令
   - 需要抽象 flags/side effect、但 BPF 本身没有对应语义的 kinsn

3. **JIT fallback 需要真的实现，而不是只停留在设计上。**

   否则很容易变成：

   - x86 native path 一直工作
   - fallback 从未被覆盖
   - 一旦移植到别的 arch 就坏

4. **select 的 verifier walk helper 必须支持局部 branch。**

   如果为了省事把 `instantiate_insn()` 限成完全直线，
   那 `select` 要么退化出更笨重的 temp/mask 序列，要么仍然需要专用逻辑。

5. **如果 future 需要“临时栈 spill/fill”，首版最好不要先做。**

   当前 5 个例子其实用不到强制栈协议。  
   论文前先把“无 spill 的版本”跑通，风险更低。

6. **时间风险。**

   当前计划文件里已经明确写了：

   - daemon 303 tests 已经在当前路径上
   - kinsn pass 还在等 verifier 侧改动激活

   这意味着现在切 full v2，会直接影响当前已经在收敛的验证链路。

---

## 6. 建议

### 6.1 是否值得在论文提交前完全转向 v2

**我的判断：不建议在论文提交前，完整转向“instantiate + 新 non-kfunc call ABI”的 full v2。**

理由不是 `instantiate` 思路不好，而是：

1. **`instantiate_insn()` 本身是好方向。**

   对当前 5 个 x86 kinsn：

   - `rotate`
   - `select`
   - `extract`
   - `endian`
   - `barrier`

   都能写出简洁、真实、可 verifier 直接理解的 BPF 展开。

2. **但“把它同时做成全新 call ABI”并不小。**

   真正的风险和工期消耗，主要在这里。

3. **对论文前目标，最值钱的是“降低 verifier 机制复杂度”，不是“再引入一套新 UAPI/新 target discovery”。**

### 6.2 更务实的建议

建议分两步：

#### 第一步：先做“compat-v2”

保留这些东西不变：

- sidecar payload
- `CALL.off = fd_slot`
- 当前 daemon 的 payload emission
- 当前按名字/BTF 发现 target 的路径

只替换这些东西：

- module 的 `model_call()` -> `instantiate_insn()`
- verifier 的 effect/apply 路径 -> instantiate walk
- JIT 的 emit 失败路径 -> translate `insn_buf`

这样能拿到 v2 的主要收益：

- verifier core 变薄
- module 更直接
- JIT fallback 更自然

而不用承担 full ABI 迁移成本。

#### 第二步：论文后再评估“纯 non-kfunc ABI”

如果提交后还有时间，再决定是否继续推进：

- `BPF_PSEUDO_KINSN_CALL`
- 新 descriptor BTF target
- 新 discovery path

这个 clean-slate 版本更纯，但不是当前最划算的一步。

### 6.3 最终结论

结论分两层：

1. **`instantiate_insn()` 方案本身：值得做。**
2. **“instantiate + 全新 non-kfunc call ABI”打包一起、在论文前切过去：不值得。**

如果只能选一个方向，我建议：

- **论文前：做 compat-v2，先把 verifier 从 effect DSL 切到 instruction instantiation。**
- **论文后：再看要不要把 call target/发现机制一并做 clean-slate。**

这条路径最符合当前代码的真实迁移成本。

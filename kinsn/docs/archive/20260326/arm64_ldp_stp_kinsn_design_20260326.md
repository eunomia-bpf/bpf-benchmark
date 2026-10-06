# ARM64 `LDP/STP` 128-bit kinsn 设计文档

日期：2026-03-26  
状态：design-only  
范围：为 BpfReJIT 设计 ARM64 `LDP/STP` pair load/store kinsn，不修改 kernel/daemon 代码

## 0. 结论摘要

结论先行：

1. 这个优化应该被定义成 **“两条顺序的 64-bit 内存访问的 native pair lowering”**，而不是“新增 128-bit BPF 标量类型”。
2. API 建议采用聚合宽度命名：`bpf_ldp128(dst1, dst2, base, off)` / `bpf_stp128(src1, src2, base, off)`。
3. **Phase 1 优先做 `STP`，其次 `LDP`。** 原因和 2026-03-24 的调研一致：真实 corpus 中相邻 `STXDW` 对远多于 `LDXDW` 对。
4. **Verifier 建模应完全走当前仓库的 v2 `instantiate_insn()` proof-lowering 模型。** 不要为这个设计回退到已经过时的 `model_call()` / `bpf_kinsn_effect` DSL。
5. **ARM64 emitter 第一版只用 signed-offset form，不用 pre/post-index。** 原因是：
   - 单 site 不需要写回 base；
   - 避免 writeback overlap 约束；
   - 更接近原始 BPF `base + off` 语义；
   - 便于和 stack / map-value / ctx 的固定偏移访存对齐。
6. **Pass 设计上它和 `WideMemPass`、未来 `BlockMemPass`/bulk-memory pass 是互补关系。**
   - `wide_mem`：`byte -> 2/4/8-byte load`
   - `ldp/stp pair`：`2 x 64-bit scalar mem -> 1 x native pair mem`
   - `bulk_mem`：长 copy/zero run，内部可以继续用 `LDP/STP`
7. **Phase 1 不做 mixed load/store 重排。** 既没有单条 mixed pair 指令，也不值得为了一条 pair 指令去改变 load/store 顺序、alias 关系和 fault/exception 行为。

一句话版本：

> 在 BPF 可见语义层维持“两条普通 `LDXDW/STXDW`”，在 ARM64 JIT 层把它们压缩成一条 `LDP/STP`。

---

## 1. 背景与设计边界

相关上下文来自：

- `docs/kernel-jit-optimization-plan.md`
- `docs/tmp/20260324/128bit_wide_loadstore_research_20260324.md`
- `docs/tmp/20260324/simd_kinsn_design_20260324.md`
- `docs/kinsn-design.md`
- `module/arm64/*.c`
- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c`

当前仓库的关键现实：

1. `kinsn` 已经是 **v2 first-class instruction**，核心接口是：
   - `instantiate_insn(payload, insn_buf)`
   - `emit_arm64(...)`
2. verifier 的主线是：
   - 识别 `sidecar + BPF_PSEUDO_KINSN_CALL`
   - `instantiate_insn()` 生成 proof sequence
   - 验证 proof sequence
   - 主分析时临时 lower 成普通 BPF
   - 分析结束后 restore 成原始 kinsn
3. ARM64 JIT 当前对普通 `BPF_LDX|STX|BPF_MEM|BPF_DW` 仍然逐条发 `LDR/STR`，没有现成 pair lowering。
4. 当前 ARM64 JIT 普通 scalar memory path 会为每条可能 fault 的内存指令接 `add_exception_handler()`。而 kinsn native emit 路径没有自动的 pair-memory extable/fixup 机制。

因此这份设计的基本原则是：

- **语义保守**：只承诺“两条普通 64-bit 访问”的语义，不承诺 128-bit atomicity。
- **第一版保守收敛**：只碰 `BPF_MEM | BPF_DW`，避开 `BPF_PROBE_MEM*` / `BPF_MEMSX` / `BPF_ATOMIC`。
- **不扩 BPF ISA**：不新增 `BPF_128`、不新增 128-bit reg type、不改 verifier lattice。

---

## 2. Pattern Analysis：哪些 BPF 序列可以被替换

## 2.1 基础候选：相邻 `LDXDW` 对

最基础的 `LDP` 候选：

```text
rA = *(u64 *)(base + off)
rB = *(u64 *)(base + off + 8)
```

约束：

- 两条都是 `BPF_LDX | BPF_MEM | BPF_DW`
- 同一个 `base`
- offset 连续，相差 8
- 两条语法上相邻
- 两个目标寄存器不同
- Phase 1 只接受 **升序地址**：`off` 后面紧跟 `off + 8`

为什么 Phase 1 只接受升序地址：

- `LDP` 没有“先读高地址再读低地址”的编码语义；
- pair 指令是 multi-access instruction，不应在没有额外论证时改变原始访存顺序；
- 这样 proof sequence 也能直接固定成：
  - `LDXDW [base+off] -> dst1`
  - `LDXDW [base+off+8] -> dst2`

降级语义：

```text
bpf_ldp128(dst1, dst2, base, off)
==>
dst1 = *(u64 *)(base + off)
dst2 = *(u64 *)(base + off + 8)
```

## 2.2 基础候选：相邻 `STXDW` 对

最基础的 `STP` 候选：

```text
*(u64 *)(base + off)     = rA
*(u64 *)(base + off + 8) = rB
```

约束：

- 两条都是 `BPF_STX | BPF_MEM | BPF_DW`
- 同一个 `base`
- offset 连续，相差 8
- 两条语法上相邻
- Phase 1 只接受 **升序地址**

注意：

- `src1 == src2` 是允许的，这对 zeroing、重复值填充很有价值。
- `base == src1/src2` 在 ARM64 signed-offset `STP` 上是架构允许的；但 daemon 第一版可以选择保守 skip 这类 site，API 本身不需要禁止。

降级语义：

```text
bpf_stp128(src1, src2, base, off)
==>
*(u64 *)(base + off)     = src1
*(u64 *)(base + off + 8) = src2
```

## 2.3 `LD_IMM64 + STX` 结构体初始化模式

这个模式是 `STP` 的重要来源，但 **不是另一套 ABI**，只是 `STP` matcher 的来源之一。

典型形态：

```text
rA = <const64_0>
rB = <const64_1>
*(u64 *)(base + off)     = rA
*(u64 *)(base + off + 8) = rB
```

或：

```text
rA = <const64_0>
*(u64 *)(base + off)     = rA
rB = <const64_1>
*(u64 *)(base + off + 8) = rB
```

这里有两个设计点：

1. `STP` kinsn 仍然只编码两个源寄存器，不直接编码立即数。
2. `map_inline + const_prop + dce` 之后，很多“局部 struct 初始化”会变成更规整的常量 materialization + 相邻 `STXDW` 对，pair pass 只要在这些 canonicalization pass 之后运行即可吃到收益。

也就是说：

- 不需要单独做 `bpf_stp128_imm`
- 只需要让 pass 在识别 `STXDW` 对时知道“这两个 source 是刚 materialize 的常量”即可

## 2.4 mixed load/store 序列怎么办

Phase 1 结论：**不做**。

不做的情况包括：

```text
LDXDW [A+0]
STXDW [B+0]
LDXDW [A+8]
STXDW [B+8]
```

和：

```text
LDXDW [base+0]
STXDW [base+8]
```

原因：

1. ARM64 没有 “load one lane + store one lane” 的 GPR pair 指令。
2. 为了制造 `LDP` 或 `STP` 而跨过 opposite-direction memory op 做重排，会改变：
   - alias 关系
   - 访存顺序
   - exception/fault 可见性
3. 这类序列更适合交给未来的 `bpf_memcpy_fast` / bulk-memory pass 处理，因为它们本质上是 **memory-to-memory block move**，不是 “two loads” 或 “two stores”。

因此：

- pair pass 只看 **load-load** 和 **store-store**
- mixed load/store 让给 bulk-memory family

---

## 3. kinsn API 与 Packed ABI 设计

## 3.1 API 形状

建议新增两个 ARM64 kinsn target：

- `bpf_ldp128`
- `bpf_stp128`

语义接口：

```c
bpf_ldp128(dst1, dst2, src_base, offset)
bpf_stp128(src1, src2, dst_base, offset)
```

命名为什么叫 `128`：

- BPF 语义上仍然是两个 64-bit lane；
- 但用户态 pass 的机会和 native lowering 的目标是 **一条 16-byte pair access**；
- 与未来 `memcpy_fast` / bulk-memory 设计放在同一层级时，`128` 比 `ldp64/stp64` 更直观。

## 3.2 语义定义

`bpf_ldp128`：

- 读两个相邻 64-bit 元素
- 修改两个目标寄存器
- 不承诺原子性
- 语义等价于两条升序 `LDXDW`

`bpf_stp128`：

- 向两个相邻 64-bit 元素写入两个寄存器值
- 不修改任何寄存器
- 不承诺原子性
- 语义等价于两条升序 `STXDW`

## 3.3 Packed ABI payload 设计

当前 sidecar payload 有 52 bit，完全够用。

建议统一 payload 布局：

| bits | 含义 |
| --- | --- |
| `[3:0]` | lane0 reg (`dst1` 或 `src1`) |
| `[7:4]` | lane1 reg (`dst2` 或 `src2`) |
| `[11:8]` | base reg |
| `[27:12]` | `offset_lo`，按 `s16` 解码 |
| `[31:28]` | flags/version，Phase 1 必须为 0 |
| `[51:32]` | 预留 |

设计约定：

- `offset_lo` 永远是较小地址的 offset
- `lane0` 对应 `[base + off]`
- `lane1` 对应 `[base + off + 8]`

这样好处是：

1. `instantiate_insn()` 不需要额外排序逻辑
2. ARM64 emitter 可以直接发 `LDP/STP [base, #off]`
3. daemon 侧可以把 pattern canonicalize 成唯一形式

## 3.4 transport 形状

沿用当前纯 v2 packed transport，不引入新 UAPI：

```text
[ sidecar(payload) ]
[ call kinsn desc ]
```

其中：

- `CALL.imm` = 导出的 `struct bpf_kinsn` descriptor 的 BTF VAR id
- `CALL.off` = module BTF fd slot

这和当前 `rotate` / `extract` / `endian` 完全同类。

## 3.5 寄存器约束

### `bpf_ldp128`

建议 Phase 1 强约束：

- `dst1 != dst2`
- `dst1 != BPF_REG_10`
- `dst2 != BPF_REG_10`
- `base != dst1`
- `base != dst2`

其中 `base != dst*` 是一个 **设计层面的保守约束**，不是架构绝对要求。

架构细节上，ARM64 signed-offset `LDP` 没有 writeback，因此 `Rn==Rt/Rt2` 不属于 writeback overlap 类约束；但在 BpfReJIT 里仍建议禁掉，理由是：

1. 让 proof sequence 和 native emit 的寄存器效果完全平凡一致；
2. 防止未来 emitter 为了别的 site 改成 pre/post-index 时踩 writeback overlap；
3. 避免 daemon/liveness 对多输出 kinsn 的额外复杂度。

### `bpf_stp128`

API 允许：

- `src1 == src2`
- `base == src1/src2`（架构允许，signed-offset 无 writeback）

但 daemon Phase 1 可以更保守：

- 先不特判 `base == src*` 的罕见 site
- 先把主要收益集中在 stack/local struct materialization 上

---

## 4. Verifier 建模

## 4.1 先纠正一个前提：当前仓库没有 `model_call()`

用户问题里提到的 `bpf_kinsn_effect` / `kinsn_ops model_call`，对应的是旧思路。  
**当前仓库真实主线不是这个模型。**

当前实现见 `docs/kinsn-design.md`：

- kernel 中的 descriptor 是 `struct bpf_kinsn`
- verifier 消费的是 `instantiate_insn()`
- proof sequence 才是 canonical BPF-visible semantics

因此对 `LDP/STP` 的正确 verifier 设计是：

- **不扩展 effect DSL**
- **不新增双返回值 call 模型**
- **直接用 proof sequence 表达双寄存器输出**

## 4.2 概念上的 effect

虽然 kernel 不再消费 `bpf_kinsn_effect`，但概念上可以把语义写成：

### `bpf_ldp128`

- uses: `base`
- defs: `dst1`, `dst2`
- memory effect: read 16 bytes as two ordered 8-byte reads
- atomicity: none

### `bpf_stp128`

- uses: `base`, `src1`, `src2`
- defs: none
- memory effect: write 16 bytes as two ordered 8-byte writes
- atomicity: none

这只是文档层语义摘要。  
真正被 verifier 执行和验证的仍应是 proof sequence。

## 4.3 `instantiate_insn()` 该怎么写

### `bpf_ldp128`

```c
insn_buf[0] = BPF_LDX_MEM(BPF_DW, dst1, base, off);
insn_buf[1] = BPF_LDX_MEM(BPF_DW, dst2, base, off + 8);
return 2;
```

### `bpf_stp128`

```c
insn_buf[0] = BPF_STX_MEM(BPF_DW, base, src1, off);
insn_buf[1] = BPF_STX_MEM(BPF_DW, base, src2, off + 8);
return 2;
```

这样有几个关键好处：

1. verifier 不需要新增任何 128-bit reg state。
2. 对 pointer class / range / stack-slot / map-value 的规则完全复用现有 `LDXDW/STXDW`。
3. 非 ARM64 或无 native emit 时，generic fallback 自动退回这两条 proof 指令。

## 4.4 为什么这比“给 call 返回两个寄存器”更对

因为 BPF call 语义天然是：

- 参数在 `r1-r5`
- 返回值在 `r0`

如果硬要把 `bpf_ldp128` 当成“helper-like call with two outputs”，就得引入：

- 双返回值 ABI
- verifier 新规则
- daemon 新 liveness
- JIT 特判

这和当前 v2 kinsn 的设计方向完全相反。  
proof lowering 已经把“双输出”问题自然解决了，没有理由再额外造一层 DSL。

## 4.5 fault / exception 语义

这部分必须保守。

当前普通 ARM64 JIT 标量 load/store 会在每条指令后面调用 `add_exception_handler(...)`。  
而 `emit_kinsn_desc_call_arm64()` 只负责让 module emit 原生指令，本身不补 pair-memory extable/fixup。

因此 Phase 1 必须限制为：

- `BPF_MEM`
- 非 `BPF_PROBE_MEM*`
- 非 `BPF_PROBE_MEM32*`
- 非任何依赖 exception callback 的 site

否则 native pair emit 和 proof sequence 的 fault 恢复行为不一致。

---

## 5. Daemon Pass 设计

建议新增独立 pass，例如：

- `arm64_pair_mem`
- 或更中性的 `ldst_pair`

本文统一称为 `PairMemPass`。

## 5.1 匹配总策略

Pass 扫描逻辑：

1. 线性扫描 logical BPF insn（跳过 `LD_IMM64` 的第二槽）
2. 找相邻两条 `LDXDW` 或相邻两条 `STXDW`
3. 检查：
   - 同 base
   - offset 相差 8
   - 升序地址
   - mode = `BPF_MEM`
4. 再做 ARM64-specific encodability / safety filter
5. 通过后替换成 `sidecar + call_kinsn`

## 5.2 Phase 1 matcher 约束

### `LDP`

- 两条 `BPF_LDX | BPF_MEM | BPF_DW`
- `base` 相同
- `off2 == off1 + 8`
- `dst1 != dst2`
- `dst1,dst2 != BPF_REG_10`
- `base != dst1,dst2`
- 不处在 packet-unsafe / alignment-unknown 的高风险场景，除非后续分析能证明

### `STP`

- 两条 `BPF_STX | BPF_MEM | BPF_DW`
- `base` 相同
- `off2 == off1 + 8`
- 非 atomic
- 非 `PROBE_MEM`

### `LD_IMM64 + STX` struct init

这不是单独 matcher，而是 `STP` matcher 的一个来源：

- 当 pass 看到相邻 `STXDW` 对时，可以向前看 source 是否来自 `MOV64_IMM/LD_IMM64`
- 用于打标签、统计和 policy，但 rewrite 仍然只发 `bpf_stp128`

## 5.3 对齐约束

设计上按 **保守 8-byte alignment** 处理。

Phase 1 要求：

- `off` 必须是 8 的倍数
- 也就是两个 lane 的地址都对齐到 8B

说明：

1. 这是 ARM64 pair 64-bit access 最稳妥的保守条件。
2. 我们不依赖 16-byte alignment，也不依赖 FEAT_LSE2 的 single-copy atomicity 条件。
3. `LDP/STP` 在这里被当作 “two 8-byte accesses packed into one insn”，不是 “guaranteed atomic 16-byte transfer”。

## 5.4 offset range 约束

ARM64 64-bit `LDP/STP` 的 imm7 按 8B 缩放，因此范围是：

- `-512 .. +504`
- 且必须是 8 的倍数

这意味着 pass 必须在 rewrite 前检查：

```text
off_lo % 8 == 0
-512 <= off_lo <= 504
```

为什么这个检查必须在 daemon 里做，而不是依赖 JIT “失败后回退”：

- 当前 verifier fixup 逻辑只按 “target 有无 native emit” 决定是否保留原始 kinsn；
- 一旦某个 kinsn target 有 native emit，ARM64 JIT 就会尝试发射；
- 如果 `emit_arm64()` 因 payload 不可编码返回错误，JIT 编译会直接失败，而不是对单个 site 回退 proof sequence。

所以：

- **encodability 必须是 pass 的前置条件**
- emitter 里的范围检查只应该是 debug guard，不应该承担正常回退职责

## 5.5 `WideMemPass` 的关系

两者互补，不重叠。

`WideMemPass` 当前只处理：

- `LDX_MEM(BPF_B)` byte ladder
- 合并到 `2/4/8-byte` load
- 只处理 load

`PairMemPass` 只处理：

- 已经是 `BPF_DW` 的相邻 pair
- load 和 store 都可处理

推荐顺序：

1. `wide_mem`
2. `pair_mem`

因为：

- `wide_mem` 先把 bytewise load chain 归整成 `DW`
- `pair_mem` 再把相邻 `DW + DW` 压成 pair

## 5.6 packet/context/map-value 的保守策略

需要吸取 `WideMemPass` 在 packet pointer 上曾经触发 verifier 拒绝的教训。

Phase 1 建议：

- `STP` 先重点覆盖 stack/local struct materialization
- `LDP` 先重点覆盖 stack、稳定 map-value、稳定 ctx field pair
- 对 XDP/TC 等 packet-heavy `prog_type`，如果 base 不是 `r10`，默认更保守

也就是说，第一版的重点不是“把所有 packet header pair load 都吃掉”，而是先把：

- stack zero/init
- 局部 struct 构造
- 明显的固定偏移 map-value/ctx 访存

跑通。

## 5.7 daemon 与后续 analysis 的关系

当前 daemon `insn_use_def()` 会把所有 `CALL` 视为：

- uses `r1-r5`
- defs `r0-r5`

对于已经插入的 kinsn，这是保守但不精确的。

因此 Phase 1 推荐：

- 把 `PairMemPass` 放在 pipeline 偏后位置
- 不要求后续 pass 对 `bpf_ldp128/bpf_stp128` 做精细 use/def 推理

未来如果需要让后续 pass 跨过 `ldp/stp` 继续做分析，再补一层 daemon-side `KinsnSemantics` 表即可；不要为这个去修改 kernel verifier ABI。

---

## 6. ARM64 JIT Emit 设计

## 6.1 指令 form 选择

ARM64 `LDP/STP` 有三类 addressing form：

- post-index
- pre-index
- signed offset

对单个 pair-mem kinsn，**应选 signed offset**：

```asm
ldp xA, xB, [xBase, #imm]
stp xA, xB, [xBase, #imm]
```

原因：

1. 原始 BPF 语义就是 `base + fixed off`，不需要写回 base
2. pre/post-index 会引入 writeback overlap 约束
3. signed-offset 直接适配 stack negative offset 和 ctx/map-value positive offset
4. 和 proof sequence 一一对应

pre/post-index 更适合未来 bulk-memory loop / chunked memcpy emitter，不适合这里的单 site pair access。

## 6.2 架构约束

根据 ARM A64 `LDP/STP` 定义：

- 64-bit pair 的 immediate 是 `imm7 * 8`
- 范围 `-512 .. +504`
- `LDP` 要禁止 `Rt == Rt2`
- writeback form 在 `Rn == Rt/Rt2` 时会触发 constrained-unpredictable 行为

这再次说明：

- Phase 1 选择 signed-offset form 是正确的
- `LDP` 的 `dst1 != dst2` 必须在 payload decode 层禁止

## 6.3 当前 Linux ARM64 insn helper 的一个缺口

这是实现时必须正视的点。

当前仓库里的 ARM64 helper：

- `vendor/linux-framework/arch/arm64/net/bpf_jit.h`
- `vendor/linux-framework/arch/arm64/lib/insn.c`

只给了 pair 的：

- `PRE_INDEX`
- `POST_INDEX`

底层 `aarch64_insn_gen_load_store_pair()` 也只支持这两类，没有 signed-offset pair 枚举值。

因此实现 `bpf_ldp128/bpf_stp128` 时有两条路：

1. 扩 `arch/arm64/lib/insn.c` helper，新增 signed-offset pair 枚举和封装  
   缺点：需要改 kernel helper
2. 像当前 `module/arm64/bpf_endian.c` 一样，在 module 内部自己写 raw encoder  
   优点：不需要额外 kernel 改动

**设计建议：Phase 1 采用方案 2。**

理由：

- 本课题本来就是 module-level 扩展
- 当前 `module/arm64/bpf_endian.c` 已经证明“module-local raw encoder”是可接受风格
- 可以避免为一个新 kinsn 去扩大通用 ARM64 helper 面

## 6.4 建议的 raw encoding helper

建议在未来 `module/arm64/bpf_ldp_stp.c` 内本地实现：

```c
static inline u32 a64_ldp64_off(u8 rt, u8 rt2, u8 rn, s16 off)
{
	return 0xA9400000U |
	       ((((u32)(off >> 3)) & 0x7fU) << 15) |
	       ((u32)rt2 << 10) |
	       ((u32)rn << 5) |
	       (u32)rt;
}

static inline u32 a64_stp64_off(u8 rt, u8 rt2, u8 rn, s16 off)
{
	return 0xA9000000U |
	       ((((u32)(off >> 3)) & 0x7fU) << 15) |
	       ((u32)rt2 << 10) |
	       ((u32)rn << 5) |
	       (u32)rt;
}
```

前置检查：

- `off % 8 == 0`
- `-512 <= off <= 504`
- `rt/rt2/rn` 都是合法 ARM64 GPR 编号

## 6.5 `emit_arm64()` 行为

### `bpf_ldp128`

1. decode payload
2. 验证：
   - `dst1 != dst2`
   - `dst1,dst2 != BPF_REG_10`
   - `base != dst1,dst2`
   - offset encodable
3. BPF reg -> ARM64 reg 映射
4. 发一条 `LDP`
5. `*idx += 1`

### `bpf_stp128`

1. decode payload
2. 验证 offset encodable
3. reg map
4. 发一条 `STP`
5. `*idx += 1`

两个 descriptor 都应设置：

- `max_insn_cnt = 2`
- `max_emit_bytes = 4`

## 6.6 为什么 Phase 1 不接 `add_exception_handler`

因为当前 kinsn native emit 路径没有 pair-memory extable glue。  
所以第一版不碰需要 fixup 的 load/store 模式。

后续如果要支持 `PROBE_MEM` 类 pair access，需要先设计：

- pair-insn 的 exception table entry 生成方式
- proof sequence 两条标量访存与单条 pair 指令的 fault 对应关系

这不应该和 Phase 1 混在一起。

## 6.7 code size 节省

native code size 角度，最典型的节省是：

- 两条 `LDR64/STR64`：8 bytes
- 一条 `LDP/STP`：4 bytes

同时，pair rewrite 对 bytecode 长度本身是友好的：

- 原始 `LDXDW + LDXDW` / `STXDW + STXDW`：2 条 BPF 指令
- rewrite 后 `sidecar + kinsn call`：仍然是 2 条 BPF 指令

也就是说：

- **BPF bytecode 指令数可以保持 2 -> 2**
- **native JIT image 则是 2 -> 1**

即每个已应用 site 节省：

- **1 条 ARM64 指令**
- **4 bytes native code**

如果只看 corpus syntactic upper bound：

- `200` 个 load-pair site + `1441` 个 store-pair site = `1641` 个 site
- 上界 native code size 节省约 `1641 * 4 = 6564` bytes

其中仅 `STP` Phase 1 上界：

- `1441 * 4 = 5764` bytes

注意这是 **syntactic upper bound**，真实应用数还会被以下条件继续缩小：

- 升序 offset 过滤
- alignment 过滤
- `imm7*8` range 过滤
- `PROBE_MEM` 过滤
- packet/context 风险过滤
- bulk-memory pass 已先吃掉的长 run

---

## 7. Corpus 机会量化

## 7.1 现有统计

2026-03-24 调研给出的 active macro corpus syntactic census：

| 范围 | sections | pair sites | LDX | STX | stack | non-stack |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| active macro corpus | 220 | 1641 | 200 | 1441 | 967 | 674 |
| networking tagged subset | 75 | 493 | 50 | 443 | 370 | 123 |
| xdp + sched_cls subset | 48 | 377 | 37 | 340 | 257 | 120 |

核心信息：

1. 候选 site 数量不少。
2. `STX` 明显多于 `LDX`。
3. stack 占比高，但 non-stack 也不是少数。

## 7.2 代表性分布

总 pair site 较多的家族包括：

- `kubearmor`: 559
- `bcc`: 319
- `tracee`: 262
- `calico`: 261

代表性 section：

- `calico_tc_maglev tc`: 204 total, 32 load, 172 store
- `kubearmor execve kretprobe __x64_sys_openat`: 144 store
- `tracee raw_tracepoint/sys_enter_submit`: 122 total, 33 load, 89 store
- `tracee raw_tracepoint/sys_exit_submit`: 92 store

这些数据说明：

- `STP` 不是“只对 toy micro 有用”
- 真正的来源是大量局部对象 materialization、stack spill/zero/init、以及部分 networking header/tuple copy

## 7.3 Phase 1 的实际机会判断

从 corpus 形态看，Phase 1 最有把握的机会是：

1. stack 上连续 `STXDW`
2. stack 上 zero/init
3. tracing/networking 程序里固定偏移的局部 struct 构造

这也是为什么 Phase 1 应优先 `STP`：

- 不需要双输出寄存器建模
- store 对在真实程序里数量压倒性更高
- 与 bulk zero/copy 路径天然衔接

## 7.4 预期收益

下面是 **推断**，不是已测实绩：

### code size

- 单 site：native 8B -> 4B
- 热 basic block 内：若连续有 2-4 对 site，可减少 2-4 条 GPR load/store 指令
- 整程序：预期以 code-size win 为主，尤其是 store-heavy 的 stack materialization block

### performance

这个优化不会减少总字节数，也不保证 pair-atomic；收益主要来自：

- frontend/decode 压力下降
- 指令条数下降
- AGU / scheduler 压力略降

因此更合理的预期是：

- **局部热点 block**：可见的低双位数百分比 win 是可能的
- **整程序独立 pass**：更可能是低个位数提升
- 真正的大块 copy/zero 性能收益，主要仍应由 bulk-memory pass 提供

换句话说：

- `LDP/STP pair kinsn` 是一个 **residual optimizer**
- 它补的是 bulk-memory 没吃掉、wide_mem 之后残留的相邻 `DW` 访问

---

## 8. 与其他 Pass 的交互

## 8.1 `map_inline + const_prop + dce`

这三类 pass 会增加 `STP` 机会：

- map inline 把稳定值转成常量
- const prop 把寄存器流进一步折叠
- dce 去掉中间无用指令

最终很多 site 会收敛成：

- 两个 `MOV64_IMM/LD_IMM64`
- 后面跟两条相邻 `STXDW`

因此 `PairMemPass` 应该跑在这些 canonicalization pass 之后。

## 8.2 `wide_mem`

`wide_mem` 会增加 `LDP` 机会：

- 原本 byte-ladder 的两个 8-byte chunk 经 `wide_mem` 后变成两条 `LDXDW`
- 这时 pair pass 才看得到 `DW + DW`

所以 pair pass 必须放在 `wide_mem` 之后。

## 8.3 `bulk_mem` / `bpf_memcpy_fast` / `bpf_memset_fast`

如果未来 bulk-memory pass 落地，它应优先于 pair pass。

原因：

- 长 copy/zero run 用 block-mem kinsn 更划算
- `PairMemPass` 只适合 leftover 的短 pair
- ARM64 bulk-memory emitter 内部仍然可以继续用 `LDP/STP`

推荐关系：

- `bulk_mem` 消灭长 run
- `pair_mem` 补剩余相邻 `DW` 对

## 8.4 `endian_fusion`

这里要特别注意顺序。

如果 `endian_fusion` 先跑：

- `LDXDW + BSWAP`
- 会先被收成 `bpf_endian_load64`

这样原本两个相邻 load 的 pair 信息就丢了，`LDP` 不容易再看见。

因此推荐：

- `PairMemPass` 在 `EndianFusionPass` 之前

未来如果要进一步优化“两个连续 endian-load”，那是下一阶段的组合优化，不应该阻塞 `LDP/STP` Phase 1。

## 8.5 推荐顺序

推荐 pipeline：

1. `map_inline`
2. `const_prop`
3. `dce`
4. `wide_mem`
5. `bulk_mem`（未来）
6. `pair_mem`
7. `rotate`
8. `cond_select`
9. `extract`
10. `endian_fusion`
11. `branch_flip`

如果当前还没有 `bulk_mem`，那就是：

1. `map_inline`
2. `const_prop`
3. `dce`
4. `wide_mem`
5. `pair_mem`
6. 其他 kinsn pass

---

## 9. 实施建议：Phase 切分

## 9.1 Phase 1

目标：

- ARM64-only
- 先做 `bpf_stp128`
- 可选同时做保守版 `bpf_ldp128`

约束：

- `BPF_MEM | BPF_DW`
- 相邻、同 base、升序 offset
- offset in `[-512, 504]`, `off % 8 == 0`
- 不碰 `PROBE_MEM`
- pass 放在 `wide_mem` 之后

成功标准：

- verifier 无新增类型系统复杂度
- ARM64 JIT image 中可见 `STP` / `LDP`
- 非 ARM64 或无 native emit 时自动退回 proof sequence

## 9.2 Phase 2

扩展方向：

- 放宽 `LDP` 非 stack site 的覆盖面
- 与 `bulk_mem` 协调
- 如有必要，再讨论 pair-memory exception/fixup
- 如后续 pass 需要跨 kinsn 做 dataflow，再补 daemon-side `KinsnSemantics`

不建议在 Phase 1 做的事：

- `BPF_128`
- mixed load/store 重排
- `PROBE_MEM` pair lowering
- pre/post-index form
- 为双输出造新的 kernel verifier call ABI

---

## 10. 最终建议

最终建议可以压成四句话：

1. **把它定义成 pair-memory kinsn，不是 128-bit BPF ISA 扩展。**
2. **Verifier 完全走当前 v2 `instantiate_insn()` proof-lowering，不要回退到过时的 `model_call` 思路。**
3. **ARM64 emitter 第一版只用 signed-offset `LDP/STP`，并在 daemon 里先做严格的 alignment/range/safety 过滤。**
4. **Pass 顺序上放在 `wide_mem` 之后、`endian_fusion` 之前；若未来有 bulk-memory pass，则 pair pass 作为 residual optimizer 放在其后。**

如果只允许先做一个方向，我的建议仍然非常明确：

> **先做 ARM64 `bpf_stp128`，再做 `bpf_ldp128`。**

---

## 参考

- 仓库内：
  - `docs/kinsn-design.md`
  - `docs/tmp/20260324/128bit_wide_loadstore_research_20260324.md`
  - `docs/tmp/20260324/simd_kinsn_design_20260324.md`
  - `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c`
  - `vendor/linux-framework/arch/arm64/lib/insn.c`
  - `module/arm64/bpf_endian.c`
- A64 指令定义：
  - LDP: `https://www.scs.stanford.edu/~zyedidia/arm64/ldp_gen.html`
  - STP: `https://www.scs.stanford.edu/~zyedidia/arm64/stp_gen.html`

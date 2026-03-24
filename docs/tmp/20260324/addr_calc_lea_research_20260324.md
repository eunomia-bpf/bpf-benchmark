# ADDR_CALC (LEA) 从零调研 + 设计报告

Date: 2026-03-24

## 0. 结论速览

结论先行：

1. **如果问题定义严格限定为 x86 `LEA` 对应的 `mov + shift + add` address-calc pattern，那么 ROI 很低。**
   当前 `corpus/build/**/*.bpf.o` 用 `llvm-objdump` 普查后，只有 **14 个严格命中 site**，分布在 **7 个对象**，**全部来自 tetragon**；按 prog_type 只有 `uprobe/kprobe/raw_tracepoint/tracepoint` 四类。
2. **这些严格 site 全部是 `scale=4`、`disp=0`。**
   也就是说，当前真实 corpus 基本没有用到 LEA 最有辨识度的额外表达能力：`scale=1/2/8` 和 `disp != 0`。
3. **历史 micro 数据也不支持把 LEA 放到第一优先级。**
   既往分析里 `addr_calc_stride` 甚至出现过回归，per-form LEA 基本是 `0.999x` 的中性结果，而不是像 `ROTATE`/`ENDIAN` 那样的明显 gap。
4. **ARM64 是另一个故事。**
   ARM64 的 `ADD shifted register` 能覆盖比 x86 LEA 更宽的 shifted-add 家族；如果把模式放宽到任何 `lsh + add`，`shift=4` 的 site 单独就有 **1893** 个，主要在 `tracee/KubeArmor`。这说明“ARM64 opportunity”大于“x86 LEA opportunity”，但那已经不是一个纯 `bpf_lea64` 问题，而更像泛化的 `shifted_add` family。

所以建议是：

- **不要把 `ADDR_CALC (LEA)` 作为第一波 pass。**
- 如果一定要做，先做一个**严格、低风险、x86-oriented** 的 `bpf_lea64` MVP。
- 如果目标是 ARM64 或跨架构覆盖率，应该单独立题为 **generic shifted-add**，不要把它伪装成一个“LEA pass”。

---

## 1. x86 LEA 指令本体

`LEA` 的核心语义是：

```text
dst = base + index * scale + disp
scale ∈ {1, 2, 4, 8}
```

对本项目最重要的几个事实：

- `LEA` **不访问内存**，只是做地址表达式计算。
- 它本质上是一个 **3-input integer op**：`base`、`index*scale`、`disp`。
- 在 x86-64 中，它天然适合把 BPF 里的“复制索引 -> 左移 -> 加 base -> 可选加常量”压成 1 条指令。
- `disp` 在机器码层面可以是 `disp8` 或 `disp32`；对 packed ABI 来说，直接按 **signed 32-bit displacement** 编码最自然。
- **scale 只有 1/2/4/8。** 这点非常关键：很多真实 BPF address calc 是 `<<= 4` 甚至更大，x86 LEA 根本表达不了。
- `LEA` 不改 flags，这让它比某些 `ADD`/`SHL` 序列更容易插在 compare/branch 邻近区域而不破坏控制流依赖。

对本项目 emitter 的直接含义：

- `bpf_lea64` 的 canonical 语义应当是 x86-shaped，而不是泛化乘加。
- ABI 里编码的应该是 `scale_log2 ∈ {0,1,2,3}`，而不是任意 shift。
- 如果未来要支持 `shift=4` 甚至更高，那已经不是 `LEA`，应另起 family。

---

## 2. BPF bytecode 里的 address-calc pattern

### 2.1 最干净的 canonical form

本项目里最典型、最适合直接映射到 LEA 的 BPF 序列是：

```text
rTmp = rIndex
rTmp <<= K        ; K ∈ {1, 2, 3}
rTmp += rBase
[rTmp += disp]    ; 可选
```

`micro/programs/addr_calc_stride.bpf.c` 就是专门人为制造这个形状。其已编译 BPF bytecode 代表片段如下：

```text
r1 = r3
r1 <<= 0x3
r1 += r2
r0 = *(u64 *)(r1 + 0x0)
```

这是最标准的 `base + index*8` 形式，直接对应：

```text
lea dst, [base + index*8]
```

### 2.2 corpus 中真实命中的 strict 片段

当前 corpus 的代表性 strict 命中来自 tetragon：

```text
6940: r1 = r8
6941: r1 <<= 0x2
6942: r1 += r7
6943: r1 = *(u32 *)(r1 + 0x10)
```

这正是 `base=r7, index=r8, scale=4` 的 LEA-eligible site。

另一个实际片段：

```text
6715: r1 = r7
6716: r1 += 0x4
6717: r2 = r8
6718: r2 <<= 0x2
6719: r2 += r1
6726: r1 = *(u32 *)(r2 + 0x4)
```

这里 local site 本身仍然是 strict `mov+shift+add`，只是 `base` 在进入 site 前已经被预偏移了。

### 2.3 不要把“所有 shifted-add”都当成 LEA

真实程序里还有很多 address-calc 看起来像这样：

```text
r1 <<= 0x4
r3 += r1
```

例如 `corpus/build/tetragon/bpf_generic_lsm_output.bpf.o` 中就有：

```text
119: r1 <<= 0x20
120: r1 s>>= 0x20
121: r1 <<= 0x4
122: r3 += r1
```

这类模式说明两件事：

1. 真实程序里的 address calc 很多是 **broader shifted-add family**，并不带前导 `mov`。
2. `shift=4` 对应 `scale=16`，**x86 LEA 无法表达**。

所以报告后面的 corpus 统计明确分成两层：

- **主统计**：只算 strict LEA-eligible `mov+shift+add`
- **补充观察**：更广义的 `lsh+add` 家族，用来讨论 ARM64 和 future generalized pass

---

## 3. Corpus 统计：基于 `llvm-objdump` 的 strict LEA census

### 3.1 统计口径

扫描方法：

- 扫描路径：`corpus/build/**/*.bpf.o`
- 扫描工具：`llvm-objdump -dr --no-show-raw-insn`
- 本次实际扫到 **568 个** `.bpf.o` 对象

strict matcher 定义：

```text
[0] mov dst, index
[1] lsh dst, K          ; K ∈ {1,2,3}
[2] add dst, base
[3] add dst, imm        ; optional, 用于记录 disp
```

约束：

- 只认 **64-bit register form**
- `K` 只认 `1/2/3`，因为这是 x86 LEA 可表达的 `scale=2/4/8`
- 不把 `mov+add`（scale=1 的 degenerate 情况）算进去，避免引入过多假阳性
- 不把“只有 `lsh+add` 没有前导 `mov`”算进主统计
- 不把 `shift>=4` 算进主统计，因为那已经不是 LEA

### 3.2 主结果

#### 按项目

| 项目 | strict LEA sites | 对象数 |
| --- | ---: | ---: |
| tetragon | 14 | 7 |
| 其他所有项目 | 0 | 0 |

#### 按 prog_type

| prog_type | sites |
| --- | ---: |
| uprobe | 6 |
| kprobe | 4 |
| raw_tracepoint | 2 |
| tracepoint | 2 |

#### 按对象

| 对象 | sites |
| --- | ---: |
| `tetragon/bpf_generic_kprobe.bpf.o` | 2 |
| `tetragon/bpf_generic_rawtp.bpf.o` | 2 |
| `tetragon/bpf_generic_retkprobe.bpf.o` | 2 |
| `tetragon/bpf_generic_retuprobe.bpf.o` | 2 |
| `tetragon/bpf_generic_tracepoint.bpf.o` | 2 |
| `tetragon/bpf_generic_uprobe.bpf.o` | 2 |
| `tetragon/bpf_generic_usdt.bpf.o` | 2 |

#### 按 scale / displacement

| 维度 | 结果 |
| --- | --- |
| scale=2 | 0 |
| scale=4 | 14 |
| scale=8 | 0 |
| disp!=0 | 0 |

最重要的事实是：

- **严格 LEA site 只有 14 个**
- **100% 集中在 tetragon**
- **100% 是 scale=4**
- **100% 没有显式 displacement**

这意味着当前 corpus 几乎没有“值得专门为 LEA expression power 付实现成本”的真实覆盖。

### 3.3 补充观察：如果放宽到 broader shifted-add

这部分不是主结论，只是为了回答“是不是 pass 太窄了”。

#### A. 只看 `lsh+add`，shift 仍限制在 `1/2/3`

如果不要求前导 `mov`，仅统计：

```text
lsh reg, {1,2,3}
add dst, reg
```

则一共能看到 **235** 个 site，前几大来源：

| 项目 | sites |
| --- | ---: |
| tetragon | 116 |
| scx | 41 |
| loxilb | 34 |
| bcc | 17 |
| tracee | 15 |

这说明：

- 如果 willing to pay liveness/alias complexity，`ADDR_CALC` 的覆盖率可以从 14 提到 235
- 但这已经不是用户要求的严格 `mov+shift+add` 了，而是 **relaxed shifted-add**

#### B. 只看 `lsh+add` 且 `shift=4`

只统计：

```text
lsh reg, 4
add dst, reg
```

竟然有 **1893** 个 site，主要来自：

| 项目 | sites |
| --- | ---: |
| tracee | 1788 |
| KubeArmor | 67 |
| scx | 24 |
| tetragon | 10 |

这组数据非常关键，因为它说明：

- ARM64 `ADD shifted register` 有更大的潜在覆盖
- 但这些 site **不是 x86 LEA**，因为 `scale=16`
- 如果未来要做跨架构统一 family，真正有价值的题目叫 **shifted-add**，而不叫 LEA

---

## 4. ARM64 等价：`ADD+LSL` 优先，`MADD` 不是 MVP

### 4.1 最直接的等价物：`ADD shifted register`

对于 `disp=0` 的 address calc，ARM64 最自然的 lowering 是：

```text
add xDst, xBase, xIndex, lsl #K
```

这和 x86 LEA 的关系是：

- x86: `lea dst, [base + index*(1<<K)]`
- arm64: `add dst, base, index, lsl #K`

对 `scale=2/4/8` 的 strict LEA family，这是 ARM64 的一条指令等价物。

### 4.2 带 displacement 的情况

ARM64 没有一条“LEA with arbitrary disp32”的完全对等指令。

可行设计：

1. `disp=0`
   - 一条 `ADD shifted register`
2. `disp` 可编码为 `ADD/SUB imm12`（或 `imm12 << 12`）
   - 两条指令：`ADD shifted` + `ADD/SUB imm`
3. 其他 `disp`
   - **MVP 不做**
   - emitter 返回 `-EINVAL`，站点回退到 instantiated BPF 序列

这和当前 strict census 是匹配的：因为真实 strict corpus 里 **没有任何 `disp!=0` site**。

### 4.3 `MADD` 的位置

`MADD` 语义是：

```text
dst = base + index * mul_reg
```

它更适合：

- 一般化乘加
- runtime multiplier 已经在寄存器里
- 或 future `smallmul_strength_reduce` 之类的 ALU family

它**不适合作为本题 MVP**，原因：

- `LEA` 的 scale 是固定小集合 `{1,2,4,8}`，不需要 materialize 乘数寄存器
- `MADD` 会把“address calc”问题扩大成“通用 strength reduction”问题
- 当前 corpus strict LEA census 太小，不值得一上来做泛化

### 4.4 ARM64 对本题的真正启示

ARM64 并不是“x86 LEA 的另一个 emitter”而已；它其实提示我们：

- `bpf_lea64` 这种 x86-shaped canonical form 只能覆盖很小一部分 shifted-add
- ARM64 真正更值得做的是 **generic shifted-add family**

因此，如果只做本题要求的 `bpf_lea64`，ARM64 emitter 可以写，但它的价值会被人为限制。

---

## 5. kinsn module 设计：`bpf_lea64`

### 5.1 建议语义

定义：

```text
bpf_lea64(dst, base, index, scale_log2, disp)
=> dst = base + (index << scale_log2) + disp
```

其中：

- `scale_log2 ∈ {0,1,2,3}`
- 对应 x86 scale `1/2/4/8`
- `disp` 为 signed 32-bit

注意：

- 这里名字叫 `lea64`，就不要把接口扩成“任意 shift”或“任意 multiply-add”
- 否则 canonical form 的边界会和 `smallmul_strength_reduce`、ARM64 shifted-add family 混在一起

### 5.2 packed ABI 布局

建议 payload 如下：

| bits | 含义 |
| --- | --- |
| 0..3 | `dst_reg` |
| 4..7 | `base_reg` |
| 8..11 | `index_reg` |
| 12..13 | `scale_log2` |
| 14..15 | reserved |
| 16..47 | `disp_s32` |
| 48..63 | reserved |

为什么这样设计：

- 和现有 `rotate/select/extract/endian` 一样，延续 4-bit reg packing
- `scale_log2` 只要 2 bit
- `disp_s32` 直接对齐到 bit 16，decode 最简单：`(s32)(payload >> 16)`
- 还保留了高 16 bit，后续如果真要加 flags，不需要重做 ABI

### 5.3 `instantiate_insn()` 语义回放

对 strict MVP，回放成：

```text
mov dst, index
if scale_log2 != 0: lsh dst, scale_log2
add dst, base
if disp != 0: add dst, disp
```

`max_insn_cnt = 4` 即可。

这个 instantiate 设计的好处：

- verifier 看到的是非常普通的 BPF ALU 序列
- 不需要给 module 暴露 `bpf_reg_state`
- 和现有 kinsn “kernel 保安全、userspace 保正确性”的模型完全一致

### 5.4 x86 emitter 设计

输出：

```text
lea x86_dst, [x86_base + x86_index * scale + disp]
```

实现要点：

- `scale_log2=0/1/2/3` 分别映射到 SIB scale `1/2/4/8`
- `disp=0` 时不编码位移
- `disp` fits `disp8` 时发短编码，否则发 `disp32`
- `dst` 可以和 `base/index` 别名，不需要额外 scratch

一个对当前代码有利的小事实：

- `module/include/kinsn_common.h` 的 x86 BPF reg 映射没有把任何 BPF reg 放到 SIB index 不可编码的 code `4`
- 所以本项目当前寄存器分配下，不需要为了 “RSP 不能做 index” 再额外加一个 verifier 限制

### 5.5 ARM64 emitter 设计

MVP：

- `disp == 0`
  - `add xDst, xBase, xIndex, lsl #scale_log2`
- `disp != 0` 且可编码
  - `add shifted`
  - `add/sub imm12`
- 其他情况
  - 返回 `-EINVAL`，site-local fallback

`max_emit_bytes` 可按 8 字节或 12 字节上界保守配置。

### 5.6 代码接入点

最小接入面和现有 kinsn 完全一致：

- `module/x86/bpf_lea.c`
- `module/arm64/bpf_lea.c`
- `module/x86/Makefile`
- `module/arm64/Makefile`
- `module/load_all.sh`
- `daemon/src/pass.rs` 里增加 `lea64_btf_id`、`kfunc_name_for_pass("addr_calc")`
- `daemon/src/kfunc_discovery.rs` 增加 `"bpf_lea64"` 发现
- `daemon/src/passes/addr_calc.rs`
- `daemon/src/passes/mod.rs` 注册 `AddrCalcPass`

---

## 6. Daemon pass 设计：`AddrCalcPass`

### 6.1 Phase 1：strict matcher

第一阶段只做 strict 版本：

```text
mov dst, index
lsh dst, K
add dst, base
[add dst, disp]
```

匹配条件：

- `K ∈ {1,2,3}`
- 同一 basic block 内，site 中间没有 branch target
- `mov/lsh/add` 全是 64-bit register ALU
- 只允许单一 `dst` 在 site 内被连续定义

rewrite 方式：

```text
sidecar(payload(dst, base, index, scale_log2, disp))
call bpf_lea64
```

这个阶段的优点：

- matcher 简单
- 基本不需要 live-out guard
- 和本次 strict census 口径完全一致

缺点也很明显：

- 覆盖率只有 14 sites / 7 objects

### 6.2 Phase 2：relaxed matcher + live-out check

如果后续想把 coverage 从 14 拉到更像样的数量，必须支持 relaxed form，例如：

```text
lsh idx, K
add dst, idx
```

或：

```text
mov tmp, idx
lsh tmp, K
mov dst, base
add dst, tmp
```

这时 **live-out check** 就是必须的。

核心原因：

- 原始代码会修改 `idx/tmp`
- LEA rewrite 往往只修改 `dst`
- 如果被缩放的寄存器在 site 后仍 live，那么 rewrite 会改变程序语义

因此 relaxed 版本至少要检查：

```text
scaled_reg ∉ liveness.live_out[last_pc_of_site]
```

也就是说：

- strict form：live-out 不是关键约束
- relaxed in-place form：**live-out 是硬门槛**

这也是我建议把“strict MVP”和“coverage 扩张版”分两阶段做的主要原因。

### 6.3 displacement 的来源

`disp` 可以来自三种地方：

1. strict 站点内部的尾随 `add dst, imm`
2. 前面已经 bias 过的 base reg
3. 站点后紧邻 load/store 的 `off`

对 MVP 的建议是：

- **只做 1**
- 2 和 3 都会把 matcher 变成局部 value-tracking / memory-op folding 问题

因为本次 strict corpus 统计里 `disp!=0` 本来就是 0，所以没有必要为一个目前不存在的真实分布先把 pass 复杂化。

### 6.4 pass 顺序建议

建议顺序：

1. `wide_mem`
2. `endian_fusion`
3. `addr_calc`（如果存在）

理由：

- `wide_mem/endian` 直接拥有 memory op，本身就更接近“最终 addressing mode”
- `addr_calc` 只是压缩前导地址计算
- 如果未来要做 “addr_calc + load/store offset fold”，那更应该和 memory-op family 合并设计，而不是抢它们的工作

---

## 7. 和其他优化的关系

### 7.1 和 `wide_mem` / `endian_fusion`

这三者都和 memory path 有关，但层级不同：

- `wide_mem`：重写 load ladder 本身
- `endian_fusion`：重写 `load + bswap`
- `addr_calc`：只重写 load/store 之前的地址计算

所以 standalone `LEA` 只是一个中间层优化。

从长期视角看，更强的设计其实是：

```text
addr_calc + load/store  =>  直接目标架构 addressing mode
```

这在 x86 和 ARM64 上都比单独先算地址再 load 更接近理想形式。

### 7.2 和 `smallmul_strength_reduce`

`smallmul_strength_reduce` 也能用到 LEA-like lowering，例如：

```text
x*3 + base  =>  base + x + x*2
```

但这不应该并到 `ADDR_CALC` 里，因为：

- 那是纯 ALU strength reduction
- 不是地址计算
- 会把 canonical form 从“x86 LEA”膨胀成“任意小常数乘法”

正确做法是：

- `ADDR_CALC` 只管 address expression
- `smallmul_strength_reduce` 另做独立 pass

### 7.3 和 ARM64 `ADD shifted register`

这是本题最重要的 cross-arch 边界：

- x86 LEA 只支持 scale `1/2/4/8`
- ARM64 `ADD shifted register` 的 shift 能力更强

因此：

- `bpf_lea64` 是一个 **x86-shaped canonical form**
- 它不是 ARM64 shifted-add opportunity 的完整抽象

如果未来 ARM64 成为主目标，应优先考虑单独立一个 `SHIFTED_ADD` family。

---

## 8. 预估影响：值不值得做

### 8.1 如果只做 strict x86 LEA

我的判断是：**不值得列为第一波实现**。

理由有四条，而且彼此独立：

1. **覆盖太小**
   - strict corpus 只有 14 sites / 7 objects
   - 100% 在 tetragon
2. **形态太单一**
   - 全部是 `scale=4`
   - 全部没有 `disp`
   - 说明 LEA 的额外表达能力几乎没被用到
3. **既有 micro 证据不强**
   - 历史报告中 `addr_calc_stride` 出现过 `-5.6%` 回归
   - per-form LEA 基本是 `0.999x`，近似中性
4. **竞争者太多**
   - `ENDIAN_FUSION`、`BITFIELD_EXTRACT`、bounds-check elimination、const-prop/DCE 都有更大真实覆盖

我的预估是：

- 就算 strict `bpf_lea64` 完整实现，**对 corpus geomean 几乎不可见**
- 更可能只在个别 tetragon 子程序上带来轻微 code-size 收缩
- 很难成为论文里值得单列的 headline optimization

### 8.2 如果愿意做 relaxed shifted-add

这时答案会变成：

- **可能有一点意义**
- 但那已经不是“LEA 从零调研”的原问题

因为 relaxed `lsh+add`（只限 shift=1/2/3）已经是 **235 sites**
，而 `shift=4` 更是 **1893 sites**。

但这条路会立刻引入：

- liveness 约束
- alias 约束
- base/index provenance 追踪
- x86 与 ARM64 canonical form 不再统一

也就是说，真正值得做的不是 strict `LEA pass`，而是另一个更大的设计题。

### 8.3 最终建议

优先级建议：

1. **本轮直接跳过 strict `ADDR_CALC (LEA)` 实现**
2. 如果只是想补齐体系结构完整性：
   - 做一个小而保守的 `bpf_lea64` MVP
   - 仅支持 strict matcher
   - 明确标注 low priority
3. 如果真正想追求跨架构收益：
   - 另起题做 `generic shifted-add`
   - 不要把它伪装成 “LEA pass”

一句话总结：

> **strict LEA 值得设计，但不值得优先实现；真正可能有价值的是更广义的 shifted-add family，而那已经是另一个优化。**

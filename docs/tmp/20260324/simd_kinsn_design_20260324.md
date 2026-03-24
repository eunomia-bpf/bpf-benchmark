# SIMD kinsn 设计报告

日期: 2026-03-24

参考输入:

- `docs/kernel-jit-optimization-plan.md`
- `docs/tmp/20260323/simd_constprop_opportunity_analysis_20260323.md` Part 1

## 0. 结论

先给结论:

- `bpf_memcpy_fast` / `bpf_memset_fast` 的 **v1 不应直接上 SSE2/AVX2/NEON**。x86 先走 `rep movsb/stosb`，ARM64 先走 `LDP/STP` / `XZR` 路径。
- `bpf_crc32` 的 **native emitter 可以很便宜**: x86 用 scalar `crc32{b,w,l,q}`，ARM64 用 scalar `crc32{b,h,w,x}` / `crc32c*`。但它和 `memcpy/memset` 不同，**当前 instantiate-only kinsn core 下 verifier 建模不够顺**，所以它是 **phase 2**，不是 memcpy/memset 那样的 phase 1。
- daemon 侧不应该做“拦截显式 memcpy/memset helper”，而应该新增一个 **BlockMemPass**，直接识别已经被 LLVM 展开的 **scalarized fixed-size block** 与 **stack zeroing**。
- v1 只做 **XDP/TC**，不做 tracing/kprobe。原因不是“XDP/TC 一定更热”，而是 **XDP/TC 的上下文更稳定、copy/zero 序列更长、FPU/NEON 风险更容易规避**。
- “SIMD kinsn” 这个方向在工程上应该拆成两层:
  - **phase 1**: 无 FPU 的 bulk-memory / CRC lowering
  - **phase 2**: 只有当长度足够大、上下文允许、并且 corpus/bench 证明值得时，才启用 AVX2/NEON/PMULL

这意味着 #421 的正确落地，不是“先写 AVX2/NEON emitter”，而是 **先把可验证、可上线、可跨机器稳定的 no-FPU 版本做出来**。

## 1. 技术路线决策

### 1.1 x86: `rep movsb/stosb` vs SSE2 vs AVX2 vs 不做

| 方案 | 优点 | 问题 | 结论 |
| --- | --- | --- | --- |
| `rep movsb/stosb` | 不碰 FPU/XMM/YMM 状态；与内核现有 string routine 方向一致；适合 fixed-size bulk copy/zero | 需要 `RDI/RSI/RCX` 特殊寄存器，x86 emitter 需要寄存器编排 | **v1 主路径** |
| SSE2 | 地址模式灵活，16B lane 好写 | 仍然要 `kernel_fpu_begin/end()`；对 16B/32B/64B 小块大概率不划算 | **reject in v1** |
| AVX2 | 大块吞吐更高 | 同样有 FPU section；微架构差异更大；收益主要在更长 buffer | **phase 2 only** |
| 不做 | 最简单 | corpus 已经看到大量 40B / 74B / 360B / 464B 连续 copy/zero run，放弃收益过大 | **reject** |

关键依据:

1. x86 内核自己的 `__memcpy` 已经把 `FSRM` fast path 直接落在 `rep movsb` 上，`__memset` 则把 `FSRS` fast path 落在 `rep stosb` 上。
2. 这些路径都 **不需要进入 kernel FPU critical section**。
3. 与此相对，任何 SSE2/AVX2 方案都要走 `kernel_fpu_begin/end()`，会禁用 preemption / softirq processing，并且在某些上下文根本不能用。

因此，x86 的正确分层是:

- **memory move / zero**: `rep` 先做
- **very large checksum / CRC**: 再讨论 PCLMUL/AVX
- **AVX512**: 明确不在第一波范围内

### 1.2 FPU break-even: 先按内核现有门槛，而不是拍脑袋

当前内核源码已经给了两个很强的 break-even 信号:

- x86 `crc32c_arch()` 对 PCLMUL 3-way path 采用 `CRC32C_PCLMUL_BREAKEVEN = 512`
- arm64 `crc32*.h` 对 PMULL 4-way path 采用 `min_len = 1024`

这两个数字不是 memcpy/memset 的直接 benchmark，但它们已经说明了一个工程事实:

- **进入 FPU/NEON section 的固定成本很高**
- 只有当 buffer 长到足以摊销状态切换、并行 lane 合并和寄存器初始化时，向量化才合理

所以本报告建议:

- **x86 SIMD/FPU gate**: `>= 512B`
- **arm64 SIMD/NEON gate**: `>= 1024B`

在这两个门槛以下，phase 1 一律不用 FPU/NEON。

### 1.3 为什么 v1 不是“真正 SIMD”，但仍然是正确的 #421 方案

`SIMD kinsn` 在机会层面说的是“让 scalarized block 重新收拢为更宽的 native 语义”。  
但在 kernel 里，**最先该收拢的不是 XMM/YMM/NEON 指令，而是 string/multi-load-store/native CRC 指令**。

换句话说:

- **“SIMD opportunity” 不等于 “v1 必须用 SIMD registers”**
- 真正重要的是 **消灭标量化后的 58 条/73 条/360 条 memory op run**

因此 #421 的 v1 目标应该写成:

- 把 `scalarized block` 收拢成 **bulk-memory kinsn**
- 先用 **不进 FPU 的 native path**
- 把 **需要 `kernel_fpu_begin/end()` 或 `kernel_neon_begin/end()` 的 emitter 放到 future tier**

## 2. kinsn module 设计

### 2.1 总体策略

沿用当前 packed kinsn 架构:

- daemon 发 `sidecar + CALL`
- verifier 通过 `instantiate_insn()` 验证 proof sequence
- JIT 通过 `emit_x86()` / `emit_arm64()` 发原生序列

新增三个 module family:

- `bpf_memcpy_fast`
- `bpf_memset_fast`
- `bpf_crc32`

其中:

- `memcpy_fast` / `memset_fast` 是 **phase 1 deliverable**
- `crc32` 是 **phase 2 reserved design**, 因为 verifier 建模比前两者难一个量级

### 2.2 `bpf_memcpy_fast`

#### 语义

```
copy len bytes from src to dst
```

v1 约束:

- `len` 必须是编译期常量
- 只处理 **non-overlap** copy，不做 memmove 语义
- 只处理 **homogeneous lane width**:
  - `1B x N`
  - `2B x N`
  - `4B x N`
  - `8B x N`
- 单个 kinsn chunk 上限 `128B`

这里坚持 homogeneous width，不是保守过度，而是为了两个现实约束:

1. **52-bit payload 不够编码任意 mixed-width lane table**
2. verifier proof sequence 必须尽量接近原始访问宽度，否则会重演 `wide_mem` 在 packet pointer 上的 verifier 问题

#### packed ABI

建议 payload:

- bits `[3:0]`: `dst_reg`
- bits `[7:4]`: `src_reg`
- bits `[11:8]`: `tmp_reg`
- bits `[13:12]`: `width_class`
  - `0 = 1B`
  - `1 = 2B`
  - `2 = 4B`
  - `3 = 8B`
- bits `[21:14]`: `lanes_minus_1`
- bits `[25:22]`: flags
  - bit0: reserved for `reverse_copy`
  - bit1: reserved for `needs_canonical_x86_regs`
  - 其他保留为 0

这里 `len = width * (lanes_minus_1 + 1)`。

#### verifier instantiate

`instantiate_insn()` 生成同宽度的重复 `LDX_MEM` + `STX_MEM` proof sequence:

- `1B x N` 就生成 `N` 组 `LDXB/STXB`
- `8B x N` 就生成 `N` 组 `LDXDW/STXDW`

不做 widen，不做 mixed-lane 重建。

这样做的价值:

- 对 packet pointer / stack / map value 的 verifier 约束最接近原始程序
- `tmp_reg` 的 live-out 语义和现有 `wide_mem`/`rotate` 风格一致
- kernel 不需要新增 verifier 特判

#### x86 emitter

v1 x86 emitter 只支持 `rep movsb`，并要求 daemon 事先把 site canonicalize 到适合 `RDI/RSI/RCX` 的寄存器形态。

具体做法:

- daemon 为 x86 选择 canonical arg regs:
  - `r1` -> `RDI` = dst
  - `r2` -> `RSI` = src
  - `r4` -> `RCX` = len/counter
- 如果 site 不能在不破坏语义的前提下拿到这些寄存器，就 **skip**
- 不在 module 里做复杂 spill/fill；复杂度放到 daemon 的 site filter，而不是放回 kernel

这听起来覆盖率会下降，但对于第一波是正确权衡:

- `rep movsb` 的收益来自长 run
- 长 run 多出现在 XDP/TC 内部 scratch build / tuple copy / map value clear
- 这些位置通常比 tracing/kprobe 更容易拿到 caller-saved scratch regs

#### arm64 emitter

ARM64 不需要固定的 `RDI/RSI/RCX` 语义，所以 emitter 更简单:

- 16B 块: `LDP/STP`
- 8B/4B/2B/1B tail: `LDR/STR`

这正好和内核当前 `memcpy.S` 的小中块策略一致。

### 2.3 `bpf_memset_fast`

#### 语义

v1 只支持 **zeroing**:

```
memset(dst, 0, len)
```

不在 v1 做“任意 fill byte”，原因很简单:

- corpus 的主要机会是 stack/map-value zero-init
- x86 `rep stos*` 需要 `RAX`
- 非零 fill 会额外引入 broadcast / byte replicate 编排

所以 v1 把问题限定为 **zero-only**，收益最大、语义最稳、proof 也最简单。

#### packed ABI

建议 payload:

- bits `[3:0]`: `dst_reg`
- bits `[5:4]`: `width_class`
- bits `[13:6]`: `lanes_minus_1`
- bits `[17:14]`: flags
  - bit0: `zero_only = 1`
  - 其余保留

`r0` 约定为 zero carrier:

- daemon 在 call 之前显式 materialize `r0 = 0`
- x86 emitter 直接复用 `RAX`
- verifier proof sequence 用 `r0` 作为 store value

这意味着 x86 v1 需要 `r0` dead-through site；不满足则 skip。

#### verifier instantiate

proof sequence 生成同宽度重复 store:

- `1B x N` -> `STXB [dst+off], r0`
- `8B x N` -> `STXDW [dst+off], r0`

因为是 zero-only，proof 非常直接，也最贴近原始 zeroing run。

#### x86 emitter

v1 选择:

- 小块/通用块统一用 `rep stosb`
- 不做 SSE2/AVX store

后续如果要进一步优化:

- 对齐良好时可以换成 `rep stosq`
- 但这是 emitter micro-opt，不是 phase 1 blocker

#### arm64 emitter

v1 选择:

- `stp xzr, xzr` 处理 16B chunk
- 尾部用 `str xzr/wzr` / `strh wzr` / `strb wzr`

`dc zva` 不进第一版默认路径，原因:

- 它对对齐和长度更敏感
- 更适合作为大块 map-value zero 的 second-step optimization
- 先把通用 `stp xzr` 跑通，已经能覆盖 corpus 里的 74B / 464B / 360B zeroing 大头

### 2.4 `bpf_crc32`

#### 为什么它和 memcpy/memset 不是同一难度

`memcpy/memset` 的 verifier proof 很自然:

- 原始程序本来就是 memory op run
- instantiate 直接还原等价 load/store 序列即可

但 `crc32` 不是这样。

如果 `bpf_crc32` 也是 packed kinsn，那么 verifier 需要一个可接受的 proof sequence。问题在于:

- base BPF ISA 没有 CRC 指令
- 把 CRC32 多项式运算展开成等价 BPF ALU 序列会非常长
- 这个 proof sequence 不再像 memcpy/memset 一样“基本等同于原程序”

所以在 **当前 instantiate-only kinsn core** 下，`bpf_crc32` 是有真实建模缺口的。

#### 设计结论

`bpf_crc32` 仍然保留在本设计里，但状态应明确写成:

- **module ABI 预留**
- **daemon detection 预留**
- **默认不进入 phase 1**

#### 目标 ABI

如果后续进入 phase 2，建议 payload:

- bits `[3:0]`: `dst_reg`  
  约定为 in/out accumulator，call 前装 seed，call 后拿结果
- bits `[7:4]`: `src_reg`
- bits `[15:8]`: `len_bytes_minus_1`
- bits `[19:16]`: flags
  - bit0: `crc32c`
  - bit1: `final_xor`
  - bit2: reserved for BE/LE variant

#### native emitter

x86:

- phase 2 默认仍应先用 **scalar CRC32 instruction chain**
- `crc32q/l/w/b` 可直接在 GPR 上做，不需要 FPU
- 只有超长 buffer 才考虑 PCLMUL/AVX path

ARM64:

- phase 2 默认先用 **scalar CRC32/CRC32C instruction chain**
- 只有长度足够长且 `PMULL + may_use_simd()` 成立时，才考虑 4-way path

#### phase 2 两条实现路径

`bpf_crc32` 真正要落地，有两种办法:

1. 保持 current packed kinsn 架构，但扩一点 verifier model，让它能描述“bounded read + scalar result transform”
2. 把它改成普通 kfunc 语义，再用 `KF_INLINE_EMIT` 做 native lowering

从“最小 kernel LOC”的角度看，**phase 1 不应为了 crc32 改 core**。  
因此 #421 的 first cut 应该是:

- 先交付 `memcpy_fast` / `memset_fast`
- 把 `crc32` 写进设计，但不承诺第一波就实现

## 3. Daemon pass 设计

### 3.1 新 pass 形态

建议新增一个统一 pass:

- `BlockMemPass`

职责:

- 识别 `scalarized fixed-size block`
- 识别 `stack zeroing pattern`
- 产出两类 lowering:
  - `bpf_memcpy_fast`
  - `bpf_memset_fast`

`crc32` 不放在这里，单独留给 `CrcFoldPass` / `ChecksumPass`。

### 3.2 pass 放在 pipeline 的位置

建议顺序:

```text
block_mem -> wide_mem -> rotate -> cond_select -> extract -> endian_fusion -> branch_flip
```

原因:

- `block_mem` 的目标是吞掉很长的 memory-op run，应该尽早做
- 它比 `rotate` / `cmov` 更像“结构级收拢”
- 先减少 40~300 条的 memory burst，再跑后续 peephole，后面的扫描成本也更低

### 3.3 识别 scalarized fixed-size block

scanner 不应只盯着“显式 builtin”，而应直接扫 BPF 指令。

#### 输入形态

匹配 maximal memory-op run:

- 连续 `LDX_MEM` / `STX_MEM` / `ST_MEM`
- 中间无 branch target 落点
- run 内不允许 helper call / tail call / exit

然后把 run 归一化成 lane:

```text
lane = {
  op: load/store,
  width: 1/2/4/8,
  base_reg,
  off,
  value_reg_or_imm
}
```

#### `memcpy_fast` 分类条件

满足以下条件时认定为 copy run:

1. run 可以切成若干 `(load, store)` pair
2. 所有 pair 的 width 相同
3. `src.off` 与 `dst.off` 都是单调连续的
4. 每个 load 的结果只被紧邻的 store 消费
5. 源/目的区间不重叠
6. 源和目的 pointer kind 在 verifier 上是兼容的
   - `packet -> stack`
   - `packet -> map value`
   - `stack -> packet`
   - `map value -> stack`
   - `map value -> map value`
7. 总长度达到最小收益门槛

建议最小门槛:

- `>= 16B` 才考虑 `memcpy_fast`
- 更小的片段保留给原始标量代码

#### 为什么 v1 只做 homogeneous-width copy

这是为了避免两个问题:

- payload 装不下 mixed width lane 描述
- proof sequence widen 后可能在 packet pointer 上被 verifier 拒绝

因此 v1 的策略是:

- `1B x N` / `2B x N` / `4B x N` / `8B x N` 直接收拢
- `4+4+2+2` 这类 mixed tail 要么拆成多个子 run，要么 skip

这不是缺陷，而是第一波正确边界。

### 3.4 识别 stack zeroing pattern

这是 `memset_fast` 的主战场。

#### 匹配条件

1. run 为纯 store-only
2. store value 都是:
   - 同一个已知为 0 的寄存器，或
   - 立即数 0
3. base 是同一个对象
   - 栈指针 `r10`
   - map value pointer
   - 某些 XDP/TC 内部 scratch object pointer
4. offset 连续
5. width 同构
6. 总长度达到阈值

建议最小门槛:

- `>= 16B` 才考虑 `memset_fast`

#### zero provenance

pass 需要一个很轻量的 backwards provenance check:

- 识别 `MOV reg, 0`
- 识别 `XOR reg, reg`
- 识别 `rX = 0` 常量载入

不需要全局 dataflow；局部 backward scan 足够。

### 3.5 chunking: 防止 verifier proof region 爆炸

这是整个设计里最容易被忽略、但实际上最重要的一点。

如果把:

- Calico 的 `58 x STXDW` 零化
- Cilium 的 `73 x STXB` 零化
- Loxilb 的 `360 x STXB` 零化

都变成一个 super-kinsn，那么:

- payload 不够表达
- `max_insn_cnt` 太大
- verifier patch/remove/restore proof region 的成本会明显上升

所以 daemon 必须在 pass 里 chunk:

- `CHUNK_MAX = 128B`

这样:

- `464B` -> `128 + 128 + 128 + 80`
- `360B` -> `128 + 128 + 104`
- `74B` -> `64 + 10` 或 `32 + 32 + 10`

这里 `128B` 不是拍脑袋:

- x86/arm64 通用 no-FPU emitter 都容易覆盖到 128B
- proof sequence 仍然可控
- 与 ARM64 当前 memcpy/memset 的 128B 小中块分界天然对齐

### 3.6 x86 寄存器约束

`rep movsb/stosb` 的真正难点不是字节串本身，而是 **固定寄存器协议**。

建议 daemon v1 明确采用“canonical x86 arg regs”策略:

- `r1` = dst (`RDI`)
- `r2` = src (`RSI`)
- `r4` = len (`RCX`)
- `r0` = zero carrier for `memset_fast` (`RAX`)

pass 只在这些寄存器 dead-through site 时应用；否则 skip。

这样做的好处:

- kernel module emitter 很小
- 不把 spill/fill 复杂度推回 kernel
- 与现有 liveness analysis 完全兼容

坏处是覆盖率会少一些。  
但 phase 1 的目标不是“100% 抓住所有 copy/zero”，而是 **先把最典型、最长、最稳的 run 收掉**。

### 3.7 ARM64 寄存器约束

ARM64 没有 `rep movsb` 这种固定寄存器协议，因此 pass 条件更宽:

- 只需要 1~2 个 caller-saved temp
- 不需要 canonicalize 到某几个特定 BPF reg

这意味着:

- 同样的 pass 在 ARM64 上理论覆盖率会更高
- 但因为 ARM64 v1 不做 NEON，收益上限也更保守

### 3.8 `bpf_crc32` pass 设计

建议单独新建:

- `CrcFoldPass`

但状态设成:

- detection-only 或 disabled-by-default

原因:

- 当前 corpus 证据里，最稳定的大头还是 copy/zero，不是 CRC fold
- `bpf_crc32` 的 verifier 建模问题还没解决

也就是说:

- `BlockMemPass` 是本轮要做的
- `CrcFoldPass` 是设计预留，不是第一波实现承诺

## 4. ARM64 设计: NEON vs LDP/STP

### 4.1 结论

ARM64 v1 选:

- `memcpy_fast`: `LDP/STP`
- `memset_fast`: `STP xzr,xzr` + 尾部 `STR*`
- `crc32`: scalar CRC32 instructions

不选:

- NEON data path
- `kernel_neon_begin/end()` 包裹的小 copy/zero

### 4.2 为什么不选 NEON

原因不是“NEON 慢”，而是“NEON 的上下文成本与 BPF 热点形状不匹配”。

当前内核规则很明确:

- `may_use_simd()` 在 hardirq / NMI 下直接不成立
- `kernel_neon_begin/end()` 需要保存/恢复 FPSIMD 上下文
- softirq/task context 也要处理嵌套和 state ownership

而 corpus 里的主要机会点是:

- 16B / 32B / 64B / 74B / 128B / 464B 这类固定块
- 不是几 KB 的长 streaming buffer

这正是 `LDP/STP` 擅长、NEON 不划算的区间。

### 4.3 ARM64 emitter 细节

`memcpy_fast`:

- `16B` lane: `ldp/stp`
- `8/4/2/1B` tail: `ldr/str`
- 对 `>128B` run 由 daemon chunk，不在 emitter 内部做复杂长循环

`memset_fast`:

- `16B` lane: `stp xzr, xzr`
- `8/4/2/1B` tail: `str xzr/wzr` / `strh wzr` / `strb wzr`
- 大块 `dc zva` 保留给后续优化，不放第一版默认路径

`bpf_crc32`:

- 用 scalar `crc32x/w/h/b` 或 `crc32cx/cw/ch/cb`
- `PMULL` 4-way 只有在 `>=1024B` 且 `may_use_simd()` 成立时才值得讨论

## 5. Corpus case: XDP/TC 最长连续 load/store 序列

下面这些 case 说明，机会点不是理论上的，而是已经在 corpus 里出现了。

| case | prog type | 连续 run | 形态 | 对应 lowering |
| --- | --- | ---: | --- | --- |
| `corpus/build/loxilb/llb_xdp_main.bpf.o:xdp_packet_func` | XDP | `362` memory ops，其中 `360` 连续 byte store | 约 `0x168B` 对象逐字节清零 | `memset_fast` |
| `corpus/build/calico/xdp_debug.bpf.o` `LBB0_9` | XDP | `58` 连续 `STXDW` | `464B` 对象清零 | `memset_fast` |
| `corpus/build/calico/xdp_no_log.bpf.o:calico_xdp_main` | XDP | `58` 连续 `STXDW` | `464B` 对象清零 | `memset_fast` |
| `corpus/build/calico/xdp_debug.bpf.o` `LBB0_36` | XDP | `40` ops = `20 load + 20 store` | 20B byte copy | `memcpy_fast` |
| `corpus/build/katran/balancer.bpf.o` `LBB0_354` | XDP | `29` ops | stack/object bytewise marshal | `memcpy_fast` 候选 |
| `corpus/build/loxilb/llb_ebpf_main.bpf.o:tc_packet_hook2` | TC | `141` ops，`72 load + 69 store` | 约 `1105B` mixed block move | `memcpy_fast` 分 chunk |
| `corpus/build/cilium/bpf_lxc.bpf.o:tail_icmp6_send_time_exceeded` | TC | `73` 连续 byte store | `74B` stack zeroing | `memset_fast` |
| `corpus/build/calico/to_hep_debug.bpf.o` `LBB0_17` | TC | `58` 连续 `STXDW` | `464B` zeroing | `memset_fast` |

补充两个“不是最长，但很说明问题”的 packet-path case:

- `xdp_flowtable.bpf.o:xdp_fwd_flow_full`
  - 入口就有 `8 x STXDW` 的 `64B` stack zeroing
  - 随后又出现固定偏移 header field copy
- `xdp_synproxy_kern.bpf.o:syncookie_xdp`
  - 有 `36B` 左右的 stack zeroing
  - 有 IPv4/IPv6 tuple/header 的 `12B` / `36B` scalar copy burst

这说明 corpus 中的真实机会点可以分成两类:

1. **长 zeroing**
2. **固定长度 header / tuple copy**

这两类都更适合 `memset_fast` / `memcpy_fast`，而不是先做 `crc32`

## 6. 风险与边界

### 6.1 NMI / hardirq / FPU 限制

这是 phase 2 SIMD path 的头号风险。

x86:

- `irq_fpu_usable()` 在 NMI 直接 false
- hardirq 下也不是总能用
- `kernel_fpu_begin/end()` 会关 preemption / softirq processing

ARM64:

- `may_use_simd()` 明确要求非 hardirq、非 NMI
- `kernel_neon_begin/end()` 需要 FPSIMD state ownership 管理

所以设计上必须把“上下文不稳”的 tracing/kprobe 排除在第一波之外。

### 6.2 微架构差异

x86:

- `rep movsb` 在有 `ERMS/FSRM` 的机器上通常很好
- 在旧机器或 feature 不齐的机器上，收益不稳定
- `AVX2` 的收益更依赖 uarch，且可能带来频率/功耗副作用

ARM64:

- `LDP/STP` 是最稳的 baseline
- NEON/PMULL 是否值得，更依赖 core 代际与 cache behavior

因此 daemon 必须扩展 `PlatformCapabilities`:

- x86: `has_erms`, `has_fsrm`, `has_fsrs`, `has_sse2`, `has_avx2`, `has_crc32`, `has_pclmulqdq`
- arm64: `has_crc32`, `has_pmull`, `has_kernel_mode_neon`

并把 `memcpy_fast` / `memset_fast` 的 x86 启用条件明确写成:

- `memcpy_fast`: 至少 `ERMS || FSRM`
- `memset_fast`: 至少 `ERMS || FSRS`

否则直接 skip。

### 6.3 verifier-friendly proof sequence

`wide_mem` 已经证明了一个教训:

- native emitter 可以很漂亮
- proof sequence 一旦改坏 pointer-width 语义，verifier 就会拒绝

所以 `memcpy_fast` / `memset_fast` v1 必须坚持:

- homogeneous width
- proof sequence 保持原宽度
- packet pointer 上不做 widen

这会少掉一些 mixed-width site，但能换来正确性和可上线性。

### 6.4 x86 register pressure

因为 `rep movsb/stosb` 绑定特殊寄存器，x86 的 pass 一定会遇到:

- canonical arg regs 不够
- `r0` / `r1` / `r2` / `r4` live-through site

v1 的策略应当是 **skip，不做 kernel-side spill/fill 复杂化**。

### 6.5 `bpf_crc32` 的 verifier model gap

这是本设计里唯一一个不应该被模糊处理的问题。

对于 `bpf_crc32`:

- emitter 很容易
- verifier proof 不容易

因此不能把它包装成“顺手一起做”。  
应该明确标为:

- **designed**
- **not first-wave implemented**

## 7. 推荐实施切分

### Phase 1A: capabilities + module skeleton

- 扩 `PlatformCapabilities`
- 扩 `KNOWN_KINSNS` / `KfuncRegistry`
- 新增:
  - `module/x86/bpf_memcpy_fast.c`
  - `module/x86/bpf_memset_fast.c`
  - `module/arm64/bpf_memcpy_fast.c`
  - `module/arm64/bpf_memset_fast.c`

### Phase 1B: daemon `BlockMemPass`

- maximal memory-op run scanner
- zeroing classifier
- homogeneous copy classifier
- x86 canonical-reg gate
- `CHUNK_MAX = 128B`
- XDP/TC only

### Phase 1C: corpus validation

- 先跑 static verify / corpus enumerate
- 重点看:
  - Calico
  - Cilium
  - Loxilb
  - xdp-tools
  - xdp_synproxy

### Phase 2: `bpf_crc32` and true SIMD tier

- 先决定 `bpf_crc32` 的 verifier 路线
- 再决定是否需要:
  - x86 PCLMUL/AVX path
  - arm64 PMULL/NEON path

## 8. 最终推荐

对 #421，我的推荐不是“做一个 AVX2/NEON 炫技版 SIMD kinsn”，而是:

1. 把 `SIMD opportunity` 重新定义为 **bulk-memory opportunity**
2. 先做 **no-FPU, verifier-friendly** 的 `bpf_memcpy_fast` / `bpf_memset_fast`
3. 把 `bpf_crc32` 明确留在 phase 2，等 verifier model 路线定了再做

如果必须压成一句话:

> #421 的正确 first cut 是 `rep movsb/stosb` + `LDP/STP` + `BlockMemPass`，不是先上 SSE2/AVX2/NEON。

# 128-bit / Wide Load-Store 优化调研报告

日期：2026-03-24  
范围基线：先阅读 `docs/kernel-jit-optimization-plan.md`，再结合 ARM64/x86 JIT、当前 `wide_mem` pass、kinsn/verifier 实现，以及 active macro corpus 做代码级调研。

## 1. 结论摘要

结论先行：

1. **ARM64 有明确机会，且应优先做 `bpf_stp64`，其次 `bpf_ldp64`。**
   当前 ARM64 BPF JIT 对 `BPF_DW` load/store 仍是逐条标量 lowering；active corpus 里“同 base、offset 相差 8 的相邻 `BPF_DW` 对”大量存在，而且 **store 远多于 load**，因此 `STP` 比 `LDP` 更值得先做。
2. **x86 不值得做原生 128-bit pair load/store 优化。**
   用 SSE2 `MOVDQU` 需要引入 XMM/FPU/SIMD 状态管理，和当前 BPF JIT 的纯 GPR 路线冲突；`REP MOVSB` 是内存到内存复制原语，不匹配“内存 <-> 两个 GPR”的 `ldp/stp` 语义。
3. **这不是 `wide_mem` 的延伸，而是另一层优化。**
   当前 `wide_mem` 只做 `byte -> 2/4/8-byte load` 合并，而且只处理 load；`128-bit / pair load-store` 应被建模为 **`word -> native pair op`**，最合理实现是新 pass + kinsn。
4. **Verifier 侧不要引入 `BPF_128`。**
   eBPF 没有 128-bit 标量/寄存器类型。最稳妥方案是：`bpf_ldp64` / `bpf_stp64` 在 verifier 中展开成两条普通 `BPF_LDX_MEM(BPF_DW)` / `BPF_STX_MEM(BPF_DW)` 证明序列，原生 JIT 只在 ARM64 上把它们压成一条 `LDP/STP`。
5. **真实程序里，IPv6-heavy 路径确实有候选，但第一波收益仍然主要来自 store。**
   Cilium 的 IPv6 tail 程序可以看到连续 64-bit load/store；xdp-tools 也有 IPv6 路径，但当前 active 节点里更常见的是栈上 struct 初始化/拷贝形成的 `STX` 对。

建议路线：

- **Phase 1**：ARM64-only `bpf_stp64`
- **Phase 2**：ARM64 `bpf_ldp64`
- **Phase 3**：若需要统一抽象，再决定是否给 x86 暴露“仅 proof-seq、无 native emit”的同名 kinsn；生产优化 pass 默认仍只在 ARM64 启用

## 2. 调研方法

本报告基于以下代码路径：

- 项目总览与现有优化路线：`docs/kernel-jit-optimization-plan.md`
- ARM64 JIT：`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c`
- x86 JIT：`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
- 当前 `wide_mem` pass：`daemon/src/passes/wide_mem.rs`
- kinsn 描述与 verifier 降级路径：
  - `vendor/linux-framework/include/linux/bpf.h`
  - `vendor/linux-framework/kernel/bpf/verifier.c`
- x86 SIMD/FPU 约束：
  - `vendor/linux-framework/Documentation/core-api/floating-point.rst`
  - `vendor/linux-framework/arch/x86/include/asm/fpu/api.h`
  - `vendor/linux-framework/arch/x86/include/asm/simd.h`
  - `vendor/linux-framework/arch/x86/kernel/fpu/core.c`
- active corpus 清单：`corpus/config/macro_corpus.yaml`

统计口径：

- 以 `macro_corpus.yaml` 中 active program/section 为准
- 共分析 **220 个 section**
- 有 **1 个缺失 section**：`linux_test_tcx_pkt_ptr` 期望的 `tcx`
- 只统计**语法上相邻**的两条 `BPF_DW` 访存：
  - load：相邻两条 `LDX_MEM(BPF_DW)`，同 `src_reg`，`abs(off2 - off1) == 8`
  - store：相邻两条 `STX_MEM(BPF_DW)`，同 `dst_reg`，`abs(off2 - off1) == 8`
- 这是 **syntactic census**，还没做 alias、liveness、faulting、alignment 二次过滤

这一定义故意偏保守。它不会高估“必须重排才能形成 pair”的机会，但会低估“中间夹了 1-2 条独立指令仍可合法成对”的机会。

## 3. ARM64：`LDP/STP` 的真实机会

### 3.1 当前 ARM64 JIT 仍是标量 load/store

在 `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c`：

- `BPF_LDX | BPF_MEM | BPF_DW` 走 `A64_LDR64I(...)` 或 `A64_LDR64(...)`
  - 关键 lowering 点在 `1765`、`1768`
- `BPF_STX | BPF_MEM | BPF_DW` 走 `A64_STR64I(...)` 或 `A64_STR64(...)`
  - 关键 lowering 点在 `1897`、`1900`
- 这些访存之后都接了 `add_exception_handler(insn, ctx, dst)`
  - 见 `1773`、`1845`、`1905`

我在该文件里检索了 `LDP/STP`，**没有现成 pair-load/store lowering**。也就是说，ARM64 后端目前完全没有把相邻两个 64-bit 访存压成单条 `LDP/STP` 的逻辑。

### 3.2 为什么 ARM64 值得做

ARM64 上这件事成立，原因很直接：

1. **ISA 有天然 pair 指令。**  
   `LDP/STP` 正好表达“两条相邻 64-bit 访存，共享一个 base+offset”。
2. **当前 JIT 缺口明确。**  
   不是“已有基础设施差一点”，而是现在根本没做。
3. **语料上 store 密度高。**  
   active corpus 中同 base、相差 8 的相邻 `STX_MEM(BPF_DW)` 远多于 `LDX_MEM(BPF_DW)`。
4. **首批安全落点很多。**  
   栈 spill/fill、本地 struct materialization、IPv6 地址/tuple 拷贝，都是 pair store/load 的自然来源。

### 3.3 最合适的第一波目标

第一波建议只做最保守的 ARM64 场景：

- 只处理 `BPF_MEM`
- 只处理 `BPF_DW + BPF_DW`
- 同 base reg
- 两条相邻
- offset 差 8
- 优先从 **stack** 和 verifier 明确可证明的 map-value/context 局部场景开始

保守起步的原因不是 ISA 不够强，而是当前 JIT 对 faulting memory access 有 extable/exception-handler 约束；pair 访存若要进入原生 emit，最好先避开 `BPF_PROBE_MEM*` 这一类需要 fixup 语义的路径。

### 3.4 `STP` 为什么应该先于 `LDP`

从 active corpus 看，候选 pair site 里：

- 总计：`1641`
- `LDX`：`200`
- `STX`：`1441`

即使只看 networking：

- networking 子集总计：`493`
- `LDX`：`50`
- `STX`：`443`

也仍然是明显的 store 优势。

这说明第一波收益更像“**struct/stack materialization 合并**”，而不是“把 packet/map 上的双 64-bit load 压成一个更宽的 load”。

## 4. x86：原生宽 load/store 基本不可取

### 4.1 当前 x86 JIT 也是纯标量 GPR 路线

在 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`：

- `emit_ldx()` 在 `1110`
- `emit_stx()` 在 `1221`
- `BPF_DW` load 用普通 `mov r64, [base+off]`
- `BPF_DW` store 用普通 `mov [base+off], r64`

这个后端没有任何 `XMM` / `SSE` / `MOVDQU` / `REP MOVSB` 路线。也就是说，x86 BPF JIT 现在的内存模型完全是“GPR <-> memory”的标量风格。

### 4.2 为什么 `MOVDQU` 听起来像答案，但实际上不是

理论上，SSE2 `MOVDQU` 可以搬 16 字节；但它不适合这里，原因有两层。

第一层是**内核执行环境**：

- `Documentation/core-api/floating-point.rst` 明确写了：内核代码默认不能随便使用 FP/SIMD 寄存器
- `arch/x86/include/asm/fpu/api.h` 要求使用 `kernel_fpu_begin/end()`
- `arch/x86/include/asm/simd.h` 的 `may_use_simd()` 最终依赖 `irq_fpu_usable()`
- `arch/x86/kernel/fpu/core.c` 中 `irq_fpu_usable()` 和 `kernel_fpu_begin_mask()` 说明了这是一套有上下文约束、保存恢复成本和可用性边界的机制

第二层是**寄存器语义不匹配**：

- `LDP/STP` 想表达的是 `memory <-> two GPRs`
- `MOVDQU` 表达的是 `memory <-> one XMM`
- 这意味着还得额外做 XMM 和两个 GPR 之间的 pack/unpack

结果就是：你为了省掉两条 `mov`，反而引入了 SIMD 上下文问题和额外 shuffle/搬运，工程复杂度与收益完全不对称。

### 4.3 为什么 `REP MOVSB` 更不对题

`REP MOVSB` 是 **memory-to-memory copy primitive**。  
它更接近“短 memcpy”，不接近“把 `[base+0]` 和 `[base+8]` 读进两个寄存器”或“把两个寄存器写回 `[base+0]` / `[base+8]`”。

因此：

- 对 `bpf_ldp64`：`REP MOVSB` 不适用
- 对 `bpf_stp64`：也不适用
- 它只可能出现在未来“memcpy-like kinsn”讨论里，而不是本报告的 pair load/store

### 4.4 x86 的现实结论

x86 最合理的方案不是“再找一种 16-byte 指令硬凑”，而是：

- **不做原生 pair load/store 优化**
- 如有统一抽象需要，可共享同名 kinsn 的 proof-seq
- 生产 pass 默认按架构 gate，只在 ARM64 启用

## 5. Corpus 统计：机会很多，但主要是 store

### 5.1 总量

| 范围 | sections | pair sites | LDX | STX | stack(base=`r10`) | non-stack |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| active macro corpus | 220 | 1641 | 200 | 1441 | 967 | 674 |
| networking tagged subset | 75 | 493 | 50 | 443 | 370 | 123 |
| xdp + sched_cls subset | 48 | 377 | 37 | 340 | 257 | 120 |

核心判断：

1. **候选并不少。**
2. **store 占绝对多数。**
3. **stack 占比高，但 non-stack 也不是少数。**

这三个事实合起来，直接支持“先做 `STP`，并且先从 stack/局部 struct 路径拿收益”。

### 5.2 家族分布

按总 pair site 数量看，前几名是：

| 家族 | 总 pair sites |
| --- | ---: |
| kubearmor | 559 |
| bcc | 319 |
| tracee | 262 |
| calico | 261 |
| xdp-tools | 58 |
| opentelemetry-ebpf-profiler | 56 |
| datadog-agent | 46 |
| loxilb | 26 |
| katran | 16 |
| linux-selftests | 14 |
| cilium | 8 |

按 **non-stack** pair site 数量看：

| 家族 | non-stack pair sites |
| --- | ---: |
| tracee | 232 |
| kubearmor | 228 |
| calico | 120 |
| opentelemetry-ebpf-profiler | 54 |
| bcc | 16 |
| datadog-agent | 15 |
| xdp-tools | 7 |
| cilium | 0 |

这里有一个重要注记：**active macro corpus 对 Cilium 明显低估。**  
原因不是 Cilium 本身没有机会，而是 active benchmark 只挑了它的入口 section，没有把真正 IPv6-heavy 的 tail programs 纳入宏观统计主视图。

### 5.3 代表性 section

总量最高的几个 section：

| section | total | LDX | STX | stack | non-stack |
| --- | ---: | ---: | ---: | ---: | ---: |
| calico_tc_maglev `tc` | 204 | 32 | 172 | 141 | 63 |
| kubearmor execve kretprobe `__x64_sys_openat` | 144 | 0 | 144 | 144 | 0 |
| tracee syscall hooks `raw_tracepoint/sys_enter_submit` | 122 | 33 | 89 | 30 | 92 |
| kubearmor `lsm/bprm_check_security` | 100 | 18 | 82 | 18 | 82 |
| tracee syscall hooks `raw_tracepoint/sys_exit_submit` | 92 | 0 | 92 | 0 | 92 |
| calico_xdp_main `xdp` | 57 | 0 | 57 | 0 | 57 |

这再次说明两件事：

- pair site 并不只出现在 stack spill/fill
- networking/XDP 路径里也存在真实 non-stack 机会

## 6. 它和 `wide_mem` pass 的关系

### 6.1 当前 `wide_mem` 实际在做什么

`daemon/src/passes/wide_mem.rs` 的当前行为非常明确：

- 入口要求首条指令是 `LDX_MEM`
- 而且必须是 `BPF_B`
  - 见 `98`
- 尝试合并的宽度只有 `2..=8`
  - 见 `106`

换句话说，当前 `wide_mem` 是：

- **byte-ladder -> 2/4/8-byte load**
- **只处理 load**
- **不涉及 128-bit**

这和“两个 64-bit 访存压成一个 native pair op”不是一回事。

### 6.2 正确的分层理解

建议把这两个优化分成两层：

1. **`wide_mem`**
   - 解决 `byte -> word`
   - 把多条 byte load 归并成普通 BPF `H/W/DW` load
2. **`pair_mem` / `ldst_pair`（新 pass）**
   - 解决 `word -> native pair op`
   - 在 BPF 语义层仍然是两条 64-bit 访存
   - 只有后端原生 emit 时才压成 `LDP/STP`

因此，二者是**互补关系**，不是替代关系。

推荐 pipeline：

1. 先跑 `wide_mem`
2. 再跑新的 `pair_mem` pass

原因：

- `wide_mem` 先把 byte-ladder 归整成规范的 `DW` load
- `pair_mem` 再去识别相邻 `DW` load/store 对

### 6.3 一个现实提醒

`docs/kernel-jit-optimization-plan.md` 已经记录过 `wide_mem` 在 packet pointer 上触发 verifier 问题的历史。  
这说明任何“变宽访存”优化都不能只看指令图样，还要尊重 verifier 对 pointer class、边界和内存模型的既有约束。

因此 pair pass 的第一版不应一开始就大面积碰 packet-pointer 复杂场景。

## 7. kinsn 设计建议：`bpf_ldp64` / `bpf_stp64`

### 7.1 为什么用 kinsn，而不是新加 `BPF_128`

当前内核里的 kinsn 机制已经足够表达这个优化：

- `struct bpf_kinsn` 在 `vendor/linux-framework/include/linux/bpf.h:969`
- sidecar payload 有 **52 bit**
  - `BPF_KINSN_SIDECAR_PAYLOAD_BITS` 在 `984`
- verifier 会先把 kinsn proof sequence 实例化并验证：
  - `validate_kinsn_proof_seq()` 在 `3856`
  - `lower_kinsn_proof_regions()` 在 `3931`
  - `build_kinsn_inst_seq()` 在 `4035`
- 如果目标架构没有 native emit，verifier 最终会把它补回 proof sequence：
  - `bpf_kinsn_has_native_emit()` 在 `4024`
  - 最终选择逻辑在 `23919-23928`

这套机制正适合本题：

- verifier 看到的是两条普通 64-bit load/store
- ARM64 JIT 看到的是单条 `LDP/STP`
- x86 没有 native emit 时自动退回 proof sequence

而且这不是空想。现有 `bpf_endian_load16/32/64` 就已经在走同一套路：

- `module/arm64/bpf_endian.c` 用 `instantiate_insn` 生成普通 `LDX + BSWAP` proof sequence，再用 `emit_arm64` 直接发 `LDR/REV`
- `module/x86/bpf_endian.c` 也是先实例化 proof sequence，再由 `emit_x86` 直接编码原生指令

`bpf_ldp64/bpf_stp64` 只是把“load+bswap”换成“load-pair/store-pair”，机制上完全同类。

### 7.2 建议的抽象

建议引入两类 kinsn：

- `bpf_stp64`
- `bpf_ldp64`

其中：

- `bpf_stp64` 优先级更高
- 两者都应定义为“**等价于两条顺序的 64-bit 内存访问**”
- **不要**定义成“单条 128-bit atomic access”

这一点非常关键。  
如果语义被说成“128-bit 一次性读/写”，那就会马上撞上 BPF ISA、verifier、内存模型和原子性承诺的问题；而如果它只是“proof-seq 可验证、native emit 可压缩”的 pair access，就和现有 kinsn 设计完全一致。

### 7.3 Proof sequence 应该是什么

推荐的 proof sequence：

- `bpf_ldp64(base, off, dst_lo, dst_hi)`
  - 展开为两条 `BPF_LDX_MEM(BPF_DW, ...)`
- `bpf_stp64(base, off, src_lo, src_hi)`
  - 展开为两条 `BPF_STX_MEM(BPF_DW, ...)`

实现时建议让 pass 先做 canonicalization：

- 永远使用较小的 offset 作为 `off`
- 第二个元素固定是 `off + 8`

这样 payload 不需要额外携带“高低顺序位”。

### 7.4 Payload 足够装下

52-bit payload 远够用。一个保守布局就可以装下：

- reg0：4 bit
- reg1：4 bit
- base：4 bit
- off：16 bit
- flags：若干 bit

即便后面要加：

- `is_store`
- `allow_unaligned`
- `base_is_fp`
- 预留版本位

也完全够。

### 7.5 保守约束建议

`bpf_ldp64` 第一版建议加这些约束：

- `dst0 != dst1`
- `base != dst0`
- `base != dst1`
- 只允许 `BPF_MEM`

原因很简单：load 会写寄存器，proof sequence 的顺序语义要和 native emit 保持一致；避免 base 被 clobber 是最便宜的办法。

`bpf_stp64` 可以更宽松一些，因为 store 不改写寄存器；但第一版依然建议只做：

- 相邻两条 `STX_MEM(BPF_DW)`
- 同 base
- offset 差 8
- 非 atomic
- 非 probe-mem

### 7.6 x86 需不需要同名 kinsn

有两个可行策略：

1. **只在 ARM64 暴露 kfunc/kinsn**
   - 最直接
   - daemon pass 也天然只在 ARM64 开
2. **两架构都暴露同名 kinsn，但 x86 只提供 instantiate、不提供 native emit**
   - 更利于共享 verifier/test 路径
   - 但生产 pass 仍应在 x86 默认关闭，因为它最终会退化成原来的两条指令

如果目标是尽快做出论文可用结果，我更倾向：

- **实现层面统一名字**
- **优化层面只在 ARM64 启用**

## 8. Verifier 挑战：难点不在“能不能验证两条 64-bit”，而在“不要偷偷改变语义”

### 8.1 没有 128-bit 类型，这反而是好事

eBPF 没有 128-bit 标量寄存器，也没有现成的 `BPF_128` 访存类别。  
所以正确方向不是扩 ISA，而是借助现有 kinsn proof-seq：

- verifier 继续验证两条普通 64-bit 指令
- 不需要新增 128-bit reg state
- 不需要改 tnum lattice
- 不需要新 pointer class

### 8.2 需要明确约束的语义点

真正要提前写清楚的是这些语义：

1. **不是 128-bit atomic access**
2. **等价于两条顺序的 64-bit access**
3. **fault/fixup 语义必须和 proof sequence 对齐**
4. **寄存器 clobber 顺序必须可解释**

其中第 3 点尤其重要。当前 ARM64 标量 load/store 每条之后都能接 `add_exception_handler(...)`；而原生 kinsn emit 路线目前没有现成的“自动为 pair memory op 生成等价 extable/fixup”框架。  
这意味着第一版最好避开 `BPF_PROBE_MEM*` 和任何依赖 fault recovery 的路径。

### 8.3 Packet pointer 场景为什么要晚一点做

项目里已经有过 `wide_mem` 碰 packet pointer verifier 边界的经验。  
pair load/store 也一样：虽然目标只是两条 `DW` access，但只要它发生在 packet/context pointer 上，就可能牵涉：

- pointer range 精度
- 对齐假设
- verifier 对等价变换的接受度

因此第一版建议优先：

- stack
- map value
- 已知 verifier 行为稳定的局部内存

## 9. Case Study：IPv6-heavy 程序

### 9.1 Cilium：active 宏观统计低估了真实机会

active macro corpus 里的 Cilium 只统计到 **8 个** pair site，看起来很少。  
但这是采样入口 section 导致的低估，不代表真实 IPv6-heavy 代码没有机会。

直接看 `corpus/bcf/cilium/clang-21_-O1_bpf_xdp.o` 的 IPv6 tail sections：

| section | total | LDX | STX | insns |
| --- | ---: | ---: | ---: | ---: |
| `2/21 tail_nodeport_ipv6_dsr` | 16 | 1 | 15 | 1056 |
| `2/18 tail_nodeport_rev_dnat_ingress_ipv6` | 10 | 0 | 10 | 1048 |
| `2/37 tail_nodeport_nat_ingress_ipv6` | 22 | 4 | 18 | 2366 |
| `2/16 tail_nodeport_nat_egress_ipv6` | 38 | 0 | 38 | 3281 |
| `2/10 tail_lb_ipv6` | 36 | 4 | 32 | 3044 |

在 `tail_nodeport_nat_ingress_ipv6` 的反汇编里，可以直接看到同一 base 上连续 64-bit load：

```text
422: r1 = *(u64 *)(r8 + 0x8)
423: r2 = *(u64 *)(r8 + 0x10)
424: r0 = *(u64 *)(r8 + 0x18)
425: r6 = *(u64 *)(r8 + 0x20)
```

这说明：

- Cilium 的 IPv6-heavy 路径确实会形成可以继续配对的 64-bit load chain
- 但即使在这些 section 里，**store 仍然更多**

从源代码看，`runner/repos/cilium/bpf/bpf_xdp.c` 的 IPv6 逻辑里也有典型的 16-byte 地址复制，例如 `prefilter_v6()` 对 `ipv6_hdr->saddr` 的拷贝。

### 9.2 xdp-tools：也有 IPv6，但当前热点更像 struct 初始化

xdp-tools 对应对象文件统计：

| object/section | total | LDX | STX | insns |
| --- | ---: | ---: | ---: | ---: |
| `xdp_flowtable.bpf.o:xdp` | 14 | 0 | 14 | 2744 |
| `xdp_forward.bpf.o:xdp` | 14 | 0 | 14 | 302 |
| `xdp_load_bytes.bpf.o:xdp` | 0 | 0 | 0 | - |

其中最典型的图样不是 packet 上的连续 load，而是栈上连续 store，例如：

```text
*(u64 *)(r10 - 0x38) = r2
*(u64 *)(r10 - 0x40) = r2
...
*(u64 *)(r10 - 0x70) = r2
```

这类模式通常来自：

- `__builtin_memset`
- 本地 `struct bpf_fib_lookup` 初始化
- IPv6 tuple / `in6_addr` materialization

也就是说，xdp-tools 证明了两件事：

1. networking/XDP 程序里 pair store 很常见
2. 第一波收益不一定来自 packet payload load，而常常来自“为后续 helper/逻辑准备本地结构体”的连续 store

## 10. ARM64 vs x86 可行性对比

| 维度 | ARM64 | x86 |
| --- | --- | --- |
| 现成原生指令 | 有 `LDP/STP` | 无对应的 GPR pair load/store |
| 与当前 BPF JIT 风格匹配度 | 高 | 低 |
| 需要引入 SIMD/FPU 状态管理 | 不需要 | 若走 `MOVDQU` 则需要 |
| proof-seq 降级模型 | 自然 | 自然 |
| 对 `bpf_stp64` 的预期收益 | 高 | 低 |
| 对 `bpf_ldp64` 的预期收益 | 中 | 低 |
| 实现复杂度 | 中 | 高 |
| verifier 风险 | 可控 | 本身不难，但没有性能回报 |
| 推荐程度 | 强烈推荐 | 不推荐做 native path |

一句话总结：

- **ARM64：值得做**
- **x86：可以共享抽象，不值得做原生实现**

## 11. 建议的实施顺序

### Phase 1：ARM64 `bpf_stp64`

原因：

- corpus 里 `STX` 压倒性更多
- stack/local-struct 路径最稳定
- 不涉及 load-side base clobber 问题

建议第一版范围：

- 只识别相邻 `STX_MEM(BPF_DW)`
- 同 base、offset 差 8
- 只在 ARM64 pass 启用
- 只对 `BPF_MEM` 生效

### Phase 2：ARM64 `bpf_ldp64`

增加约束：

- `base != dst0/dst1`
- `dst0 != dst1`
- 初版继续避开 probe/faulting load

### Phase 3：如果论文需要跨架构统一抽象

- 给 x86 暴露同名 kinsn 的 instantiate-only 版本
- daemon 仍默认只在 ARM64 把它作为优化启用

## 12. 最终建议

本题不应被定义成“给 eBPF 加 128-bit 类型”，而应被定义成：

> 在 BPF 语义层维持“两条普通 64-bit 访存”，在 ARM64 JIT 层把它们压缩成单条 `LDP/STP`。

这条路线和现有 BpfReJIT 设计最一致：

- 和 `wide_mem` 的分工清晰
- 和 kinsn/verifier 的 proof-seq 框架兼容
- 对 ARM64 有真实收益
- 不会把 x86 拖进 SIMD/FPU 的工程泥潭

如果只允许选一个最先落地的方向，我的建议非常明确：

**先做 ARM64 `bpf_stp64`。**
